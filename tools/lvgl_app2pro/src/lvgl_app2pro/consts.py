"""Pull colors and repeated numbers out of the screens and into globals.xml.

A converted UI is full of the same handful of colors and spacings written out
hundreds of times. Naming them once is most of what makes the output worth
keeping, so this runs over the finished style values before anything is written.
"""

import re
from collections import Counter

from .model import walk

_COLOR = re.compile(r"^0x[0-9a-f]{6}$")
_NUMBER = re.compile(r"^-?\d+$")

# Values that are structural rather than design decisions. Naming them adds
# noise without telling the reader anything.
_TRIVIAL_NUMBERS = {"0", "1", "-1"}


class Consts:
    """The named constants, and the lookup that rewrites values into `#name`."""

    def __init__(self):
        self.colors = {}   # value -> name
        self.numbers = {}  # value -> name

    def substitute(self, value):
        name = self.colors.get(value) or self.numbers.get(value)
        return f"#{name}" if name else value

    @property
    def empty(self):
        return not self.colors and not self.numbers

    def items(self):
        """Definitions in a stable order: colors first, then numbers."""
        for value, name in sorted(self.colors.items(), key=lambda kv: kv[1]):
            yield "color", name, value
        for value, name in sorted(self.numbers.items(), key=lambda kv: int(kv[0])):
            yield "int", name, value


def _node_slots(node):
    """Every style slot on a node, its scale sections included.

    A section's styles are slots like any other - they just hang off the section
    rather than the node, and would otherwise miss out on consts.
    """
    yield from node.slots
    for section in node.sections:
        yield from section["styles"].values()


def _all_style_values(screens):
    """Every style property value in the project, with repeats."""
    for screen in screens:
        for node in walk(screen.root):
            for slot in _node_slots(node):
                for _, value in slot.props:
                    yield value


def collect(screens, number_repeats=3):
    """Name every color, and every number used at least `number_repeats` times.

    Colors are named on sight because a color is a design decision even when it
    appears once. A number only earns a name once it repeats, otherwise every
    one-off padding would become a const.
    """
    counts = Counter(_all_style_values(screens))
    consts = Consts()

    for value, _ in sorted(counts.items()):
        if _COLOR.match(value):
            consts.colors[value] = f"color_{value[2:]}"

    for value, count in sorted(counts.items()):
        if not _NUMBER.match(value) or value in _TRIVIAL_NUMBERS:
            continue
        if count >= number_repeats:
            consts.numbers[value] = f"num_{value.replace('-', 'minus_')}"

    return consts


def _substituted(slot, consts):
    return type(slot)(
        selector=slot.selector,
        props=tuple((name, consts.substitute(value)) for name, value in slot.props),
        is_local=slot.is_local,
    )


def apply(screens, consts):
    """Rewrite every style value that has a const into a `#name` reference."""
    if consts.empty:
        return
    for screen in screens:
        for node in walk(screen.root):
            node.slots = [_substituted(slot, consts) for slot in node.slots]
            for section in node.sections:
                section["styles"] = {
                    key: _substituted(slot, consts)
                    for key, slot in section["styles"].items()
                }
