# ===========================================================================
#  PC simulator for the UI exported from LVGL Pro.
#
#  This is a self-contained wrapper used only to compile, run and debug the UI
#  on a desktop. It fetches LVGL, generates an lv_conf.h, sets up the SDL
#  (Linux/macOS) or native Windows display/input backend and links against the
#  `lib-ui` library built by the exported project's own CMakeLists.txt one
#  level up.
#
#  The real project (the parent folder) stays focused on the UI itself; nothing
#  here is needed when the UI is built into a firmware/application.
#
#  Configure this folder (sim/) as the CMake source directory to build and
#  debug the simulator.
# ===========================================================================

cmake_minimum_required(VERSION 3.16)
project(lvgl_simulator C)

# Build with debug symbols by default (so breakpoints work) unless the user
# picked a build type. Multi-config generators (Visual Studio) ignore this and
# choose the config at build time instead.
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# LVGL version to fetch (any git tag or branch from https://github.com/lvgl/lvgl)
set(LVGL_VERSION "v9.5.0" CACHE STRING "LVGL version (git tag or branch)")

# Folder with the UI exported from LVGL Pro (the parent of this sim/ folder).
set(UI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.." CACHE PATH "Folder with the exported UI")

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")

# ---------------------------------------------------------------------------
#  Fetch LVGL
# ---------------------------------------------------------------------------
include(FetchContent)
# Silence the FetchContent_Populate deprecation warning (CMake >= 3.30).
if(POLICY CMP0169)
  cmake_policy(SET CMP0169 OLD)
endif()
FetchContent_Declare(
  lvgl
  GIT_REPOSITORY https://github.com/lvgl/lvgl.git
  GIT_TAG ${LVGL_VERSION}
  GIT_SHALLOW TRUE)

FetchContent_GetProperties(lvgl)
if(NOT lvgl_POPULATED)
  message(STATUS "Fetching LVGL ${LVGL_VERSION}. It might take a few minutes ...")
  FetchContent_Populate(lvgl)
endif()

# ---------------------------------------------------------------------------
#  Generate lv_conf.h from the platform's lv_conf defaults
#
#  Each lv_conf_*.defaults only lists the options we override; every other
#  option is taken from LVGL's own lv_conf_template.h. The display/input
#  backend is baked into the per-platform defaults file we pick here.
# ---------------------------------------------------------------------------
find_package(Python3 REQUIRED COMPONENTS Interpreter)

if(WIN32)
  # On Windows use LVGL's built-in Win32 driver (no external dependency).
  set(LV_CONF_DEFAULTS "${CMAKE_CURRENT_SOURCE_DIR}/lv_conf_windows.defaults")
else()
  # On Linux and macOS use SDL2.
  set(LV_CONF_DEFAULTS "${CMAKE_CURRENT_SOURCE_DIR}/lv_conf_sdl.defaults")
endif()

set(LV_CONF_PATH "${CMAKE_BINARY_DIR}/lv_conf.h")
# Generate to a temp file first, then copy only when the contents changed so
# lv_conf.h keeps its timestamp across reconfigures and LVGL is not rebuilt
# on every build.
set(LV_CONF_TMP "${CMAKE_BINARY_DIR}/lv_conf.h.in")
execute_process(
  COMMAND ${Python3_EXECUTABLE}
          "${lvgl_SOURCE_DIR}/scripts/generate_lv_conf.py"
          --template "${lvgl_SOURCE_DIR}/lv_conf_template.h"
          --defaults "${LV_CONF_DEFAULTS}"
          --config   "${LV_CONF_TMP}"
  RESULT_VARIABLE _conf_result
  OUTPUT_VARIABLE _conf_output
  ERROR_VARIABLE  _conf_output)
if(NOT _conf_result EQUAL 0)
  message(FATAL_ERROR "Failed to generate lv_conf.h:\n${_conf_output}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${LV_CONF_TMP}" "${LV_CONF_PATH}")
message(STATUS "Generated ${LV_CONF_PATH} from ${LV_CONF_DEFAULTS}")

# Re-run CMake (and regenerate lv_conf.h) when the defaults file changes.
set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS
             "${LV_CONF_DEFAULTS}")

# Tell LVGL to use the generated lv_conf.h.
set(LV_BUILD_CONF_PATH "${LV_CONF_PATH}" CACHE PATH "" FORCE)

# ---------------------------------------------------------------------------
#  Add LVGL (keep the build minimal: skip bundled demos/examples/ThorVG)
# ---------------------------------------------------------------------------
set(CONFIG_LV_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(CONFIG_LV_BUILD_DEMOS OFF CACHE BOOL "" FORCE)
set(CONFIG_LV_USE_THORVG_INTERNAL OFF CACHE BOOL "" FORCE)

add_subdirectory(${lvgl_SOURCE_DIR} ${lvgl_BINARY_DIR})

# ---------------------------------------------------------------------------
#  Display / input backend
# ---------------------------------------------------------------------------
set(BACKEND_LIBS "")
if(WIN32)
  # LVGL's Windows driver only needs the Win32 GDI libraries.
  list(APPEND BACKEND_LIBS gdi32 user32)
else()
  # SDL2 provides the window, mouse and keyboard on Linux/macOS.
  find_package(SDL2 REQUIRED)
  target_include_directories(lvgl SYSTEM PUBLIC ${SDL2_INCLUDE_DIRS})
  list(APPEND BACKEND_LIBS ${SDL2_LIBRARIES})
endif()

# ---------------------------------------------------------------------------
#  UI exported from LVGL Pro
#
#  The parent folder ships its own CMakeLists.txt that builds a `lib-ui`
#  target. It is outside this source tree, so a binary dir must be given.
# ---------------------------------------------------------------------------
add_subdirectory(${UI_DIR} ${CMAKE_BINARY_DIR}/ui)

# The generated UI C uses `#include "lvgl.h"` style includes when this is
# defined, matching the fetched LVGL target's include directories.
target_compile_definitions(lib-ui PUBLIC LV_LVGL_H_INCLUDE_SIMPLE)

# Derive the UI entry point and window size from the exported project.xml so the
# simulator stays generic: the library header is "<name>.h" and its init
# function is "<name>_init".
file(READ "${UI_DIR}/project.xml" _project_xml)
string(REGEX MATCH "<project[^>]*name=\"([^\"]+)\"" _ "${_project_xml}")
set(UI_NAME "${CMAKE_MATCH_1}")
if(NOT UI_NAME)
  # Fall back to the parent folder's name when project.xml has no usable name.
  get_filename_component(UI_NAME "${UI_DIR}" ABSOLUTE)
  get_filename_component(UI_NAME "${UI_NAME}" NAME)
  message(STATUS "No project name in ${UI_DIR}/project.xml; using folder name \"${UI_NAME}\"")
endif()
string(REGEX MATCH "<display[^>]*width=\"([0-9]+)\"[^>]*height=\"([0-9]+)\"" _ "${_project_xml}")
set(UI_WIDTH "${CMAKE_MATCH_1}")
set(UI_HEIGHT "${CMAKE_MATCH_2}")
if(NOT UI_WIDTH OR NOT UI_HEIGHT)
  set(UI_WIDTH 800)
  set(UI_HEIGHT 480)
endif()

# ---------------------------------------------------------------------------
#  Application
# ---------------------------------------------------------------------------
add_executable(${PROJECT_NAME} main.c hal.c)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE lib-ui lvgl ${BACKEND_LIBS})

# Guard the sim/ files (so a glob-based embedded build skips them) and pass the
# exported UI's header, init function and window size to main.c.
target_compile_definitions(${PROJECT_NAME} PRIVATE
  LVGL_PRO_SIMULATOR_BUILD
  UI_HEADER="${UI_NAME}.h"
  UI_INIT=${UI_NAME}_init
  UI_WIDTH=${UI_WIDTH}
  UI_HEIGHT=${UI_HEIGHT})

if(NOT WIN32)
  target_link_libraries(${PROJECT_NAME} PRIVATE m pthread)
endif()

# Build and run from the UI folder so the "A:" asset path resolves to it.
add_custom_target(run
  COMMAND $<TARGET_FILE:${PROJECT_NAME}>
  WORKING_DIRECTORY ${UI_DIR}
  DEPENDS ${PROJECT_NAME})
