# Built-in Simulator

A small desktop app that compiles and runs your UI on your computer. As it can be compiled
directly in the editor and shown in a window, no embedded hardware is needed at all.

It uses the **exact same C code** that runs on the device, so the UI in the simulator behaves
the same way. The window is shown via **SDL2** on Linux/macOS and the built-in **Win32** driver on Windows.

The project can not only be compiled but also debugged in a VSCode-like debugger.

The simulator can be used to test only the behavior of the UI and the related code.
The performance and the hardware-dependent parts cannot be simulated this way.

## What's in this folder

- `main.c` — entry point; loads the UI exported from the project
- `hal.c` / `hal.h` — display and input backend (SDL2 or Win32)
- `lv_conf_sdl.defaults` / `lv_conf_windows.defaults` — per-platform LVGL config overrides
- `CMakeLists.txt` — fetches LVGL, generates `lv_conf.h`, and links the exported `lib-ui`

## Running it

**From the Editor:** press **F5** (Run / Start Debugging) to compile, run and debug.

**From the command line** (run from the project root, the parent of this folder):

```bash
cmake -S sim -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build -j
cmake --build build --target run
```

## Dependencies

- **All platforms:** CMake (≥ 3.16), Python 3, a C compiler and a debugger
- **Linux / macOS additionally:** SDL2

```bash
# Debian/Ubuntu
sudo apt install build-essential cmake gdb python3 libsdl2-dev
# Arch
sudo pacman -S base-devel cmake gdb python sdl2
# Fedora
sudo dnf install @development-tools cmake gdb python3 SDL2-devel
# macOS
brew install cmake llvm python sdl2
```

## Customizing

- Edit `main.c` to choose which screen to load. It is preserved across exports.
- Change LVGL settings in the platform-specific `lv_conf_*.defaults` file, then rebuild.

## How it works

When configured, the simulator automatically:

1. Fetches LVGL via CMake `FetchContent` (using LVGL v9.5.0 by default, can be modified in `CMakeLists.txt`)
2. Generates `lv_conf.h` from the platform-specific `lv_conf_*.defaults`
3. Builds your exported UI as the `lib-ui` library
4. Reads the project name and display size from `project.xml` and passes them to `main.c`

