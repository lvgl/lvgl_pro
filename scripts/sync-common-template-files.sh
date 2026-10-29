#!/bin/sh
#
# Copies the common template files from templates/common into every project.
#
# The Editor instantiates templates/empty, templates/basic, examples/lvgl_open and
# tutorials as standalone user projects, so each needs its own copy of the simulator,
# the VS Code settings and AGENTS.md. examples/lvgl_pro is not instantiated, but it is
# an ordinary project with the same simulator, so it gets the same files.
#
# Edit the files in templates/common, never a project's copy, then run this script.
# CI runs it and fails if anything changed, so a copy edited by hand is caught.
#
# sim/ and .vscode/ hold exactly what templates/common holds, so a file removed from
# templates/common is removed from the projects too. These stay per project:
#   sim/main.c               the screen each project loads
#   tutorials/sim/README.md  tutorials has its own longer text
#
# Run it from anywhere in the repo:  scripts/sync-common-template-files.sh

set -eu

COMMON='templates/common'
PROJECTS='templates/empty templates/basic examples/lvgl_open examples/lvgl_pro tutorials'

# Folders owned by templates/common: any other file in them is deleted.
OWNED_DIRS='sim .vscode'

cd "$(git rev-parse --show-toplevel)"

is_per_project() {
    case "$1" in
        */sim/main.c | tutorials/sim/README.md) return 0 ;;
    esac
    return 1
}

for project in $PROJECTS; do
    (cd "$COMMON" && find . -type f) | sed 's|^\./||' | while read -r relative; do
        target="$project/$relative"
        if is_per_project "$target"; then
            continue
        fi
        mkdir -p "$(dirname "$target")"
        cp "$COMMON/$relative" "$target"
    done

    for directory in $OWNED_DIRS; do
        if [ ! -d "$project/$directory" ]; then
            continue
        fi
        find "$project/$directory" -type f | while read -r target; do
            relative="${target#"$project"/}"
            if is_per_project "$target" || [ -f "$COMMON/$relative" ]; then
                continue
            fi
            echo "Removing $target, it is not in $COMMON"
            rm "$target"
        done
    done
done
