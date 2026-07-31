/**
 * Generate the `## Properties` section of every built-in-widget page, plus
 * `enums.mdx` and `style_props.mdx`, from the LVGL XML widget schemas.
 *
 * Source of truth : <widgets-dir>/lv_*.xml and <widgets-dir>/globals.xml
 * Target          : docs/built_in_widgets/*.mdx (content below the
 *                    `{/* @generated ... *\/}` marker is replaced)
 *
 * Run (Node >= 23.6, e.g. v24 — strips TS types natively, no deps):
 *
 *   node docs/scripts/gen_widget_api.ts [widgets-dir]
 *
 * On Node 22.6–23.5 add `--experimental-strip-types`. `widgets-dir`
 * defaults to the local lv_xml widgets folder (override via argv or the
 * LV_WIDGETS_DIR env var).
 */

import { readFileSync, writeFileSync, readdirSync, existsSync } from 'node:fs';
import { join, dirname, basename } from 'node:path';
import { fileURLToPath } from 'node:url';

// ---------------------------------------------------------------------------
// Minimal, lenient XML parser (tree of elements / comments, order preserved)
// ---------------------------------------------------------------------------

type Attrs = Record<string, string>;
interface ElNode { kind: 'el'; name: string; attrs: Attrs; children: Node[]; selfClosed: boolean; }
interface CommentNode { kind: 'comment'; text: string; }
type Node = ElNode | CommentNode;

function decodeEntities(s: string): string {
	return s
		.replace(/&lt;/g, '<')
		.replace(/&gt;/g, '>')
		.replace(/&quot;/g, '"')
		.replace(/&apos;/g, "'")
		.replace(/&#10;/g, '\n')
		.replace(/&#(\d+);/g, (_, d) => String.fromCodePoint(Number(d)))
		.replace(/&#x([0-9a-fA-F]+);/g, (_, h) => String.fromCodePoint(parseInt(h, 16)))
		.replace(/&amp;/g, '&');
}

function parseAttrs(raw: string): Attrs {
	const attrs: Attrs = {};
	const re = /([\w:-]+)\s*=\s*("([^"]*)"|'([^']*)')/g;
	let m: RegExpExecArray | null;
	while ((m = re.exec(raw))) attrs[m[1]] = decodeEntities(m[3] ?? m[4] ?? '');
	return attrs;
}

// A bare `<param>` is the only tag that legitimately must have a prop/element
// parent yet appears (in malformed source XML such as lv_tabview's `active`)
// as a sibling of a *self-closed* `<prop>`. `prop`/`arg` are NOT adopted —
// real top-level `<prop>`s are direct children of `<api>`.

function parseXml(src: string): ElNode {
	const root: ElNode = { kind: 'el', name: '#root', attrs: {}, children: [], selfClosed: false };
	const stack: ElNode[] = [root];
	const top = () => stack[stack.length - 1];
	let i = 0;

	while (i < src.length) {
		const lt = src.indexOf('<', i);
		if (lt === -1) break;
		i = lt;

		// Comment
		if (src.startsWith('<!--', i)) {
			const end = src.indexOf('-->', i + 4);
			const text = src.slice(i + 4, end === -1 ? src.length : end).trim();
			top().children.push({ kind: 'comment', text });
			i = end === -1 ? src.length : end + 3;
			continue;
		}

		// Find the '>' that ends this tag, skipping any inside quoted
		// attribute values (help text may contain raw '<' / '>').
		let gt = i + 1;
		let quote = '';
		for (; gt < src.length; gt++) {
			const ch = src[gt];
			if (quote) { if (ch === quote) quote = ''; }
			else if (ch === '"' || ch === "'") quote = ch;
			else if (ch === '>') break;
		}
		if (gt >= src.length) break;
		const tag = src.slice(i + 1, gt).trim();
		i = gt + 1;

		if (tag.startsWith('/')) {
			// Closing tag — pop to the matching ancestor (lenient).
			const name = tag.slice(1).trim();
			for (let s = stack.length - 1; s > 0; s--) {
				if (stack[s].name === name) { stack.length = s; break; }
			}
			continue;
		}

		const selfClosed = tag.endsWith('/');
		const body = (selfClosed ? tag.slice(0, -1) : tag).trim();
		const sp = body.search(/\s/);
		const name = sp === -1 ? body : body.slice(0, sp);
		const attrs = sp === -1 ? {} : parseAttrs(body.slice(sp + 1));
		const node: ElNode = { kind: 'el', name, attrs, children: [], selfClosed };

		// Adoption fix: orphan param/arg/prop whose intended parent was the
		// previous *self-closed* sibling (works around malformed source XML
		// such as `<prop .../>` followed by its own `<param>`s).
		let parent = top();
		if (name === 'param' && parent.name !== 'prop' && parent.name !== 'element') {
			const sib = [...parent.children].reverse().find((c): c is ElNode => c.kind === 'el');
			if (sib && sib.selfClosed && (sib.name === 'prop' || sib.name === 'element')) {
				sib.selfClosed = false;
				stack.push(sib);
				parent = sib;
			}
		}

		parent.children.push(node);
		if (!selfClosed) stack.push(node);
	}
	return root;
}

const els = (n: ElNode, name?: string): ElNode[] =>
	n.children.filter((c): c is ElNode => c.kind === 'el' && (!name || c.name === name));
const firstEl = (root: ElNode, name: string): ElNode | undefined => {
	const stack = [root];
	while (stack.length) {
		const n = stack.pop()!;
		for (const c of n.children) if (c.kind === 'el') {
			if (c.name === name) return c;
			stack.push(c);
		}
	}
	return undefined;
};

// ---------------------------------------------------------------------------
// Markdown helpers
// ---------------------------------------------------------------------------

/** Escape a value for use inside a Markdown/GFM table cell. */
function cell(s: string | undefined): string {
	if (!s) return '—';
	return s.replace(/\s+/g, ' ').replace(/\|/g, '\\|').trim() || '—';
}
const code = (s: string | undefined): string => (s ? '`' + s.replace(/\|/g, '\\|') + '`' : '—');

function table(headers: string[], rows: string[][]): string {
	if (!rows.length) return '';
	const head = `| ${headers.join(' | ')} |`;
	const sep = `| ${headers.map(() => '---').join(' | ')} |`;
	const body = rows.map((r) => `| ${r.join(' | ')} |`).join('\n');
	return `${head}\n${sep}\n${body}\n`;
}

/** Flatten a <prop> into one or more referenceable XML attribute rows. */
function propRows(p: ElNode): string[][] {
	const name = p.attrs.name;
	const params = els(p, 'param');
	if (!params.length) {
		return [[code(name), code(p.attrs.type), cell(p.attrs.help)]];
	}
	return params.map((pa) => {
		const attr = pa.attrs.name === name ? name : `${name}-${pa.attrs.name}`;
		const isMain = pa.attrs.name === name;
		let desc = isMain ? p.attrs.help || pa.attrs.help : pa.attrs.help;
		if (pa.attrs.default) desc = `${desc || ''}${desc ? ' ' : ''}(default: \`${pa.attrs.default}\`)`;
		return [code(attr), code(pa.attrs.type), cell(desc)];
	});
}

/** Render a widget enumdef as a labelled value table. */
function renderEnum(e: ElNode): string {
	const rows = els(e, 'enum').map((v) => [code(v.attrs.name), cell(v.attrs.help)]);
	const title = `**${code(e.attrs.name)}**${e.attrs.help ? ` — ${e.attrs.help}` : ''}` +
		(e.attrs.multi === 'true' ? ' _(values can be combined)_' : '');
	return `${title}\n\n${table(['Value', 'Description'], rows)}`;
}

/** Render an <element> as a subsection: heading, help, args/props table. */
function renderElement(widgetTag: string, e: ElNode): string {
	const tag = `${widgetTag}-${e.attrs.name}`;
	let out = `### \`<${tag}>\`\n\n`;
	if (e.attrs.help) out += `${e.attrs.help}\n\n`;
	const meta: string[] = [];
	if (e.attrs.access) meta.push(`access \`${e.attrs.access}\``);
	if (e.attrs.type && e.attrs.type !== 'void') meta.push(`returns \`${e.attrs.type}\``);
	if (meta.length) out += `_${meta.join(' · ')}_\n\n`;

	// The element's own parts come before its attributes.
	const parts = els(e, 'parts')[0];
	if (parts) out += `**Parts**\n\n${partsTable(parts)}\n`;

	const rows: string[][] = [];
	for (const c of els(e)) {
		if (c.name === 'arg') {
			let d = c.attrs.help || '';
			if (c.attrs.default) d += `${d ? ' ' : ''}(default: \`${c.attrs.default}\`)`;
			rows.push([code(c.attrs.name), 'arg', code(c.attrs.type), cell(d)]);
		} else if (c.name === 'prop') {
			for (const r of propRows(c)) rows.push([r[0], 'prop', r[1], r[2]]);
		}
	}
	out += rows.length
		? table(['Name', 'Kind', 'Type', 'Description'], rows)
		: '_No attributes — created as an empty child._\n';
	return out;
}

// ---------------------------------------------------------------------------
// Per-widget Properties section
// ---------------------------------------------------------------------------

/** The "learn more about <api>" note, kept right under ## Properties. */
const API_NOTE =
	"Properties below are the widget's XML [`<api>`](../syntax/api); see " +
	'[API](../syntax/api) for how properties, parameters and elements work.';

const INHERIT_NOTE =
	'This widget adds no XML properties of its own — it inherits the full ' +
	'API of the [Base Widget (`lv_obj`)](./lv_obj). See ' +
	'[API](../syntax/api) for how the `<api>` works.';

/** Intro shown above every Parts table. */
const PARTS_NOTE =
	'Style parts of the widget with local style (e.g. `style_bg_color-knob="0xff0000"`)' +
	' or with style sheets (e.g. `<style name="style_knob" selector="knob">`). ' +
	'See [Styles](../syntax/styles) to learn more.';

/** Render a `<parts>` block as a Part / Description table. */
function partsTable(parts: ElNode): string {
	const rows = els(parts, 'part').map((p) => [code(p.attrs.name), cell(p.attrs.help)]);
	return table(['Part', 'Description'], rows);
}

function renderWidget(key: string, api: ElNode): string {
	if (key === 'lv_obj') return renderBaseWidget(api);

	const out: string[] = [];

	// Enumerations come first, as their own top-level section.
	const enums = els(api, 'enumdef');
	if (enums.length) {
		out.push('## Enumerations\n');
		out.push(enums.map(renderEnum).join('\n'));
	}

	out.push('## Properties\n');

	const consts = els(api, 'const');
	const props = els(api, 'prop');
	const elements = els(api, 'element');
	const parts = els(api, 'parts')[0];

	// Parts open the section, before any properties.
	if (parts) {
		out.push('### Parts\n');
		out.push(`${PARTS_NOTE}\n`);
		out.push(partsTable(parts));
	}

	if (!consts.length && !props.length && !elements.length) {
		out.push(INHERIT_NOTE);
		return out.filter(Boolean).join('\n').trim();
	}

	out.push(`${API_NOTE}\n`);

	if (consts.length) {
		out.push('### Constants\n');
		out.push(table(['Name', 'Description'],
			consts.map((c) => [code(c.attrs.name), cell(c.attrs.help)])));
	}
	if (props.length) {
		out.push(table(['Property', 'Type', 'Description'], props.flatMap(propRows)));
	}
	for (const e of elements) out.push(renderElement(key, e));

	return out.filter(Boolean).join('\n').trim();
}

// ---------------------------------------------------------------------------
// lv_obj — the base widget, grouped logically
// ---------------------------------------------------------------------------

const EVENT_ELEMENTS = new Set([
	'event_cb', 'screen_load_event', 'screen_create_event', 'play_timeline_event',
	'subject_toggle_event', 'subject_set_int_event', 'subject_set_float_event',
	'subject_set_string_event', 'subject_increment_event',
]);
const STYLING_ELEMENTS = new Set(['style', 'remove_style', 'remove_style_all']);

const LOCAL_STYLE_SECTION = `### Local style properties

Any style property can be set directly on a widget as a \`style_<property>\`
attribute. These are *local styles* — they affect only that one instance.
Add a \`-<part>\` and/or \`-<state>\` selector to target a part or state:

\`\`\`xml
<lv_obj
  style_bg_color="0x1f2937"
  style_bg_color-pressed="0x111827"
  style_radius="8" />
\`\`\`

\`lv_obj\` exposes the **full** style catalogue (\`style_bg_color\`,
\`style_pad_all\`, \`style_text_font\`, …) — too many to list here. See
[Style Properties](./style_props) for the complete list, and
[Styles](../syntax/styles) for selectors, parts, states and reusable
named \`<style>\` sheets.`;

function renderBaseWidget(api: ElNode): string {
	const props = els(api, 'prop');
	const isStyle = (p: ElNode) => p.attrs.name.startsWith('style_');
	const isObjFlag = (p: ElNode) => (p.attrs.type || '').startsWith('flag:flag');
	const isStateFlag = (p: ElNode) => (p.attrs.type || '').startsWith('flag:state');
	const isBind = (p: ElNode) => p.attrs.name.startsWith('bind_');

	const plain = props.filter((p) => !isStyle(p) && !isObjFlag(p) && !isStateFlag(p) && !isBind(p));
	const objFlags = props.filter(isObjFlag);
	const stateFlags = props.filter(isStateFlag);
	const bindProps = props.filter(isBind);

	const elements = els(api, 'element');
	const styling = elements.filter((e) => STYLING_ELEMENTS.has(e.attrs.name));
	const events = elements.filter((e) => EVENT_ELEMENTS.has(e.attrs.name));
	const flagBinds = elements.filter((e) => e.attrs.name.startsWith('bind_flag_if_'));
	const stateBinds = elements.filter((e) => e.attrs.name.startsWith('bind_state_if_'));
	const styleBinds = elements.filter((e) =>
		e.attrs.name === 'bind_style' || e.attrs.name === 'bind_style_prop');

	const out: string[] = [];

	// lv_obj has only the lv_obj_flag enumdef, which the Flags section
	// already documents — so no separate ## Enumerations section here.
	out.push('## Properties\n');

	const parts = els(api, 'parts')[0];
	if (parts) {
		out.push('### Parts\n');
		out.push(`${PARTS_NOTE}\n`);
		out.push(partsTable(parts));
	}

	out.push(`${API_NOTE}\n`);
	out.push(table(['Property', 'Type', 'Description'], plain.flatMap(propRows)));

	out.push('### Flags\n');
	out.push('Boolean object flags — set as `flag="true"` / `"false"`.\n');
	out.push(table(['Flag', 'Description'],
		objFlags.map((p) => [code(p.attrs.name), cell(p.attrs.help)])));

	out.push('### State flags\n');
	out.push('Force a widget state on or off — set as `state="true"` / `"false"`.\n');
	out.push(table(['State', 'Description'],
		stateFlags.map((p) => [code(p.attrs.name), cell(p.attrs.help)])));

	out.push('### Styling\n');
	for (const e of styling) out.push(renderElement('lv_obj', e).replace(/^### /, '#### '));
	out.push(LOCAL_STYLE_SECTION);

	out.push('### Events\n');
	out.push('Attach behaviour that runs on an `lv_event` trigger.\n');
	for (const e of events) out.push(renderElement('lv_obj', e).replace(/^### /, '#### '));

	out.push('### Data bindings\n');
	out.push('Drive widget state, flags or styles from an observer ' +
		'[subject](../syntax/data-binding).\n');
	for (const e of styleBinds) out.push(renderElement('lv_obj', e).replace(/^### /, '#### '));
	if (bindProps.length) {
		out.push('#### Bound properties\n');
		out.push(table(['Property', 'Type', 'Description'], bindProps.flatMap(propRows)));
	}
	const sharedArgs = (e: ElNode) =>
		table(['Name', 'Type', 'Description'],
			els(e, 'arg').map((a) => [code(a.attrs.name), code(a.attrs.type), cell(a.attrs.help)]));
	if (flagBinds.length) {
		const ops = flagBinds.map((e) => code(e.attrs.name.replace('bind_flag_if_', ''))).join(', ');
		out.push('#### `<lv_obj-bind_flag_if_*>`\n');
		out.push(`Set or clear an object flag from a subject. One element per ` +
			`comparison — operators: ${ops} (e.g. \`<lv_obj-bind_flag_if_eq>\`).\n`);
		out.push(sharedArgs(flagBinds[0]));
	}
	if (stateBinds.length) {
		const ops = stateBinds.map((e) => code(e.attrs.name.replace('bind_state_if_', ''))).join(', ');
		out.push('#### `<lv_obj-bind_state_if_*>`\n');
		out.push(`Apply a widget state from a subject. One element per ` +
			`comparison — operators: ${ops} (e.g. \`<lv_obj-bind_state_if_eq>\`).\n`);
		out.push(sharedArgs(stateBinds[0]));
	}

	return out.filter(Boolean).join('\n').trim();
}

// ---------------------------------------------------------------------------
// globals.xml → enums.mdx + style_props.mdx
// ---------------------------------------------------------------------------

function renderGlobalEnums(api: ElNode): string {
	const enums = els(api, 'enumdef');
	return enums
		.map((e) => {
			const rows = els(e, 'enum').map((v) => [code(v.attrs.name), cell(v.attrs.help)]);
			const sub = e.attrs.multi === 'true' ? ' _(values can be combined)_' : '';
			return `### \`${e.attrs.name}\`\n\n${e.attrs.help || ''}${sub}\n\n` +
				table(['Value', 'Description'], rows);
		})
		.join('\n');
}

function renderStyleProps(styledef: ElNode): string {
	const groups: { title: string; rows: string[][] }[] = [{ title: '', rows: [] }];
	for (const c of styledef.children) {
		if (c.kind === 'comment') groups.push({ title: c.text, rows: [] });
		else if (c.kind === 'el' && c.name === 'prop')
			groups[groups.length - 1].rows.push(
				[code(c.attrs.name), code(c.attrs.type), cell(c.attrs.help)]);
	}
	return groups
		.filter((g) => g.rows.length)
		.map((g) => (g.title ? `### ${g.title}\n\n` : '') +
			table(['Property', 'Type', 'Description'], g.rows))
		.join('\n');
}

// ---------------------------------------------------------------------------
// Replace the region below the `@generated` marker
// ---------------------------------------------------------------------------

function injectBelowMarker(file: string, generated: string): boolean {
	const lines = readFileSync(file, 'utf8').split('\n');
	const start = lines.findIndex((l) => l.includes('@generated'));
	if (start === -1) return false;
	let end = start;
	while (end < lines.length && !lines[end].includes('*/}')) end++;
	const head = lines.slice(0, end + 1).join('\n');
	writeFileSync(file, `${head}\n\n${generated.trim()}\n`);
	return true;
}

// ---------------------------------------------------------------------------
// Main
// ---------------------------------------------------------------------------

const here = dirname(fileURLToPath(import.meta.url));
const docsDir = join(here, '..');
const repoRoot = join(docsDir, '..');
const bwDir = join(docsDir, 'built_in_widgets');

// Default to the newest `lvgl_widgets_xml/v*` folder in this repo. Override with
// argv[2] or LV_WIDGETS_DIR to document a different LVGL version.
function latestWidgetsDir(): string {
	const root = join(repoRoot, 'lvgl_widgets_xml');
	if (!existsSync(root)) return root;
	const versions = readdirSync(root)
		.filter((d) => /^v\d/.test(d))
		.sort((a, b) => a.localeCompare(b, undefined, { numeric: true }));
	return versions.length ? join(root, versions[versions.length - 1]) : root;
}

const widgetsDir =
	process.argv[2] ||
	process.env.LV_WIDGETS_DIR ||
	latestWidgetsDir();

function main() {
	if (!existsSync(widgetsDir)) {
		console.error(`Widgets dir not found: ${widgetsDir}`);
		process.exit(1);
	}

	let widgets = 0;
	for (const mdx of readdirSync(bwDir).filter((f) => /^lv_.*\.mdx$/.test(f)).sort()) {
		const key = basename(mdx, '.mdx');
		const xml = join(widgetsDir, `${key}.xml`);
		if (!existsSync(xml)) { console.warn(`! no XML for ${key}, skipped`); continue; }
		const api = firstEl(parseXml(readFileSync(xml, 'utf8')), 'api');
		if (!api) { console.warn(`! no <api> in ${key}.xml, skipped`); continue; }
		if (!injectBelowMarker(join(bwDir, mdx), renderWidget(key, api)))
			console.warn(`! no @generated marker in ${mdx}, skipped`);
		else widgets++;
	}

	const gpath = join(widgetsDir, 'globals.xml');
	const groot = parseXml(readFileSync(gpath, 'utf8'));
	const gapi = firstEl(groot, 'api');
	let extra = 0;
	if (gapi) {
		if (injectBelowMarker(join(bwDir, 'enums.mdx'), renderGlobalEnums(gapi))) extra++;
		const styledef = firstEl(gapi, 'styledef');
		if (styledef && injectBelowMarker(join(bwDir, 'style_props.mdx'), renderStyleProps(styledef)))
			extra++;
	}

	console.log(`Generated API docs for ${widgets} widgets + ${extra} reference pages.`);
}

main();
