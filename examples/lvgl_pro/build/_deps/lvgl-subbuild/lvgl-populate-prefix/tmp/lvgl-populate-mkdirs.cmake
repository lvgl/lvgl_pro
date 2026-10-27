# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/home/kisvegabor/projects/lvgl/editor/lvgl_pro/examples/lvgl_pro/build/_deps/lvgl-src")
  file(MAKE_DIRECTORY "/home/kisvegabor/projects/lvgl/editor/lvgl_pro/examples/lvgl_pro/build/_deps/lvgl-src")
endif()
file(MAKE_DIRECTORY
  "/home/kisvegabor/projects/lvgl/editor/lvgl_pro/examples/lvgl_pro/build/_deps/lvgl-build"
  "/home/kisvegabor/projects/lvgl/editor/lvgl_pro/examples/lvgl_pro/build/_deps/lvgl-subbuild/lvgl-populate-prefix"
  "/home/kisvegabor/projects/lvgl/editor/lvgl_pro/examples/lvgl_pro/build/_deps/lvgl-subbuild/lvgl-populate-prefix/tmp"
  "/home/kisvegabor/projects/lvgl/editor/lvgl_pro/examples/lvgl_pro/build/_deps/lvgl-subbuild/lvgl-populate-prefix/src/lvgl-populate-stamp"
  "/home/kisvegabor/projects/lvgl/editor/lvgl_pro/examples/lvgl_pro/build/_deps/lvgl-subbuild/lvgl-populate-prefix/src"
  "/home/kisvegabor/projects/lvgl/editor/lvgl_pro/examples/lvgl_pro/build/_deps/lvgl-subbuild/lvgl-populate-prefix/src/lvgl-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/kisvegabor/projects/lvgl/editor/lvgl_pro/examples/lvgl_pro/build/_deps/lvgl-subbuild/lvgl-populate-prefix/src/lvgl-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/kisvegabor/projects/lvgl/editor/lvgl_pro/examples/lvgl_pro/build/_deps/lvgl-subbuild/lvgl-populate-prefix/src/lvgl-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
