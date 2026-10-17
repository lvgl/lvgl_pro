cmake_minimum_required(VERSION 3.14)
project(lv_demo_widgets C CXX)

# Everything is fetched and generated here, so building needs nothing but a
# compiler, SDL2 and CMake:
#
#   cmake -B build && cmake --build build -j
#
# LVGL ends up in build/_deps/lvgl-src, which is also what lvgl_app2pro wants
# for --lvgl, because that is where the matching GDB plugin lives.
#
# Pass -DLVGL_DIR=<an lvgl checkout> to build against one you already have
# instead of fetching another. That is what the test suite does.

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
# The converter reads the application's debug info, so debug symbols are not
# optional - and they have to reach LVGL itself, not just this file. -g3 rather
# than -g because LVGL's version is only readable through its macros:
# lv_version_major() is `static inline` and is not emitted unless something
# calls it.
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "build type" FORCE)
endif()
add_compile_options(-g3)

# Build-time defaults; the binary also takes --width, --height and --tab.
set(DEMO_WIDTH  800 CACHE STRING "window width")
set(DEMO_HEIGHT 480 CACHE STRING "window height")
set(DEMO_TAB    0   CACHE STRING "tab the demo opens on")

find_package(SDL2 REQUIRED SDL2)

if(DEFINED LVGL_DIR)
    set(lvgl_SOURCE_DIR ${LVGL_DIR})
    set(lvgl_BINARY_DIR ${CMAKE_BINARY_DIR}/lvgl_build)
else()
    # Which LVGL to build against: -DLVGL_TAG=master to try a newer one.
    set(LVGL_TAG "v9.5.0" CACHE STRING "LVGL branch or tag to fetch")

    include(FetchContent)
    FetchContent_Declare(
        lvgl
        GIT_REPOSITORY https://github.com/lvgl/lvgl.git
        GIT_TAG        ${LVGL_TAG}
        GIT_SHALLOW    TRUE
    )
    FetchContent_Populate(lvgl)
endif()

# lv_conf.h is generated from lv_conf.defaults, so only the options this
# example cares about are kept in the repository.
execute_process(
    COMMAND ${CMAKE_COMMAND} -E env python3
            ${lvgl_SOURCE_DIR}/scripts/generate_lv_conf.py
            --template ${lvgl_SOURCE_DIR}/lv_conf_template.h
            ${CMAKE_CURRENT_SOURCE_DIR}
    RESULT_VARIABLE conf_result
)
if(NOT conf_result EQUAL 0)
    message(FATAL_ERROR "Could not generate lv_conf.h from lv_conf.defaults")
endif()

set(LV_BUILD_CONF_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lv_conf.h CACHE PATH "" FORCE)
add_subdirectory(${lvgl_SOURCE_DIR} ${lvgl_BINARY_DIR})
target_include_directories(lvgl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${SDL2_INCLUDE_DIRS})

add_executable(lv_demo_widgets main.c)
target_compile_definitions(lv_demo_widgets PRIVATE
                           DEMO_WIDTH=${DEMO_WIDTH}
                           DEMO_HEIGHT=${DEMO_HEIGHT}
                           DEMO_TAB=${DEMO_TAB})
target_include_directories(lv_demo_widgets PRIVATE
                           ${lvgl_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(lv_demo_widgets
                      lvgl lvgl::demos ${SDL2_LIBRARIES} m pthread stdc++)
