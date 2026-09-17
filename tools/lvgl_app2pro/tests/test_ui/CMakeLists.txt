cmake_minimum_required(VERSION 3.10)
project(test_ui C CXX)

# Built against whichever LVGL checkout is being tested, and its lv_conf.h.
#   cmake -B build -DLVGL_DIR=<lvgl> -DLV_CONF_DIR=<dir holding lv_conf.h>
if(NOT DEFINED LVGL_DIR)
    message(FATAL_ERROR "Pass -DLVGL_DIR=<path to an lvgl checkout>")
endif()
if(NOT DEFINED LV_CONF_DIR)
    message(FATAL_ERROR "Pass -DLV_CONF_DIR=<directory holding lv_conf.h>")
endif()

set(CMAKE_C_STANDARD 99)
# -g3 so the converter can read LVGL's version macros, the same as the example.
add_compile_options(-g3)
find_package(SDL2 REQUIRED SDL2)

add_subdirectory(${LVGL_DIR} lvgl_build)
target_include_directories(lvgl PUBLIC ${LV_CONF_DIR} ${SDL2_INCLUDE_DIRS})

# One demo asset, so the app has a real image to convert.
add_executable(test_ui test_ui.c
               ${LVGL_DIR}/demos/widgets/assets/img_lvgl_logo.c)
target_compile_definitions(test_ui PRIVATE LV_CONF_INCLUDE_SIMPLE)
target_include_directories(test_ui PRIVATE ${LVGL_DIR}/.. ${LV_CONF_DIR})
target_link_libraries(test_ui lvgl ${SDL2_LIBRARIES} m pthread stdc++)
