#!/bin/bash

set -e

# Paths are derived from this script's own location, so the checkout folder can
# be named anything and the script can be started from any directory.
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJ_PATH="$(cd "$SCRIPT_DIR/../.." && pwd)"
STARTER_PATH="$(dirname "$PROJ_PATH")"

# The docs copy of the LVGL Pro examples, written by generate_examples.py from
# the examples/lvgl_pro project. It holds nothing but examples, because the whole
# folder is dropped into the emscripten checkout as lvgl's own examples/ below.
# (`examples/lvgl_open` is the set shared with the LVGL Open docs, built elsewhere.)
EXAMPLES_PATH=$PROJ_PATH/docs/examples

export PATH="/usr/lib/ccache:/usr/local/opt/ccache/libexec:$PATH"

echo Clone the Emscripten port
echo -------------------------

cd $STARTER_PATH

if true; then
    rm -rf emscripten_builder
    git clone https://github.com/lvgl/lv_sim_emscripten.git emscripten_builder
    cd emscripten_builder
    git submodule update --init --single-branch -- lvgl
    cd lvgl
    git pull origin master
fi

EMSCRIPTEN_BUILDER_PATH=$STARTER_PATH/emscripten_builder
LVGL_PATH=$EMSCRIPTEN_BUILDER_PATH/lvgl
echo EMSCRIPTEN_BUILDER_PATH: $EMSCRIPTEN_BUILDER_PATH
echo LVGL_PATH: $LVGL_PATH

echo Generate example list
echo ---------------------

# Replace the lvgl examples with these examples so that emscripten will build them
rm -r $LVGL_PATH/examples
cp -r "$EXAMPLES_PATH" "$LVGL_PATH/examples"

cd $STARTER_PATH
EXAMPLE_LIST_C=$EMSCRIPTEN_BUILDER_PATH/examplelist.c
$SCRIPT_DIR/genexamplelist.sh $EXAMPLES_PATH > $EXAMPLE_LIST_C
cat $EXAMPLE_LIST_C

echo Generate lv_conf
echo ----------------

# Generate lv_conf
LV_CONF_PATH=$LVGL_PATH/configs/ci/docs/lv_conf_docs.h
python $LVGL_PATH/scripts/generate_lv_conf.py \
  --template $LVGL_PATH/lv_conf_template.h \
  --config $LV_CONF_PATH \
  --defaults $SCRIPT_DIR/lv_conf_docs.defaults

echo Build the examples
echo ------------------

cd $EMSCRIPTEN_BUILDER_PATH
emcmake cmake -B cmbuild -GNinja -DLV_BUILD_CONF_PATH=$LV_CONF_PATH -DLVGL_CHOSEN_DEMO=lv_example_noop -DCMAKE_C_COMPILER_LAUNCHER=ccache -DCMAKE_CXX_COMPILER_LAUNCHER=ccache
cmake --build cmbuild


echo Copy the built examples
echo -----------------------


rm -rf cmbuild/CMakeFiles
cp -a cmbuild $PROJ_PATH/docs/built_lv_examples
