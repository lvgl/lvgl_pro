#!/bin/sh
#
# Checks the common template files: the ones meant to be identical in every project.
#
# The Editor instantiates templates/empty, templates/basic, examples/lvgl_open and
# tutorials as standalone user projects, so their build and tooling files are the same
# file kept in several places. examples/lvgl_pro is not instantiated, but it is an
# ordinary project with the same simulator, so it is held to the same files.
# Nothing generates any of them, so they drift quietly: a fix lands in one project and
# the others keep the old version.
#
# This only reports. Fix a finding by copying the right version across. If two projects
# are supposed to differ, add the path to DIFFER_ON_PURPOSE below together with the
# reason.
#
# Run it from anywhere in the repo:  .github/scripts/check-common-template-files.sh

set -eu

# The project every other one is compared against.
REFERENCE='templates/empty'
OTHERS='templates/basic examples/lvgl_open examples/lvgl_pro tutorials'

# Every file under these folders must match, in every project.
COMMON_DIRS='sim .vscode'

# Individual files at the project root that must match.
COMMON_FILES='.mcp.json user_config.cmake AGENTS.md'

# Common template files that are different for a reason:
#   sim/main.c     one line each, the screen the project loads
#   sim/README.md  tutorials has its own longer text
DIFFER_ON_PURPOSE='sim/main.c sim/README.md'

cd "$(git rev-parse --show-toplevel)"

problems="$(mktemp)"
trap 'rm -f "$problems"' EXIT

is_exception() {
    for exception in $DIFFER_ON_PURPOSE; do
        if [ "$1" = "$exception" ]; then
            return 0
        fi
    done
    return 1
}

# Compare one relative path in one project against the reference.
compare() {
    project="$1"
    relative="$2"
    if [ ! -f "$project/$relative" ]; then
        echo "$project/$relative is missing" >>"$problems"
    elif ! cmp -s "$REFERENCE/$relative" "$project/$relative"; then
        echo "$project/$relative differs from $REFERENCE/$relative" >>"$problems"
    fi
}

for directory in $COMMON_DIRS; do
    if [ ! -d "$REFERENCE/$directory" ]; then
        echo "$REFERENCE/$directory does not exist, so there is nothing to compare against." >&2
        echo "Fix REFERENCE or COMMON_DIRS in $0." >&2
        exit 2
    fi
done

for project in $OTHERS; do
    for directory in $COMMON_DIRS; do
        if [ ! -d "$project/$directory" ]; then
            echo "$project/$directory is missing entirely" >>"$problems"
            continue
        fi

        find "$REFERENCE/$directory" -type f | sed "s|^$REFERENCE/||" | while read -r relative; do
            if is_exception "$relative"; then
                continue
            fi
            compare "$project" "$relative"
        done

        # A file added to one project only is drift too, so look the other way round.
        find "$project/$directory" -type f | sed "s|^$project/||" | while read -r relative; do
            if is_exception "$relative"; then
                continue
            fi
            if [ ! -f "$REFERENCE/$relative" ]; then
                echo "$project/$relative exists but $REFERENCE/$relative does not" >>"$problems"
            fi
        done
    done

    for relative in $COMMON_FILES; do
        if is_exception "$relative"; then
            continue
        fi
        compare "$project" "$relative"
    done
done

if [ -s "$problems" ]; then
    echo "The common template files drifted:"
    sed 's/^/  /' "$problems"
    echo
    echo "These files are meant to be identical in $REFERENCE $OTHERS."
    echo "Copy the right version across, or add the path to DIFFER_ON_PURPOSE in"
    echo "$0 with the reason."
    exit 1
fi

echo "Common template files are identical across $REFERENCE $OTHERS."
