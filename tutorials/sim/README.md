# Built-in Simulator

A small desktop app that compiles and runs your UI on your computer — no hardware
needed. It uses the **exact same C code** that runs on the device, so what you see
here is what you get on the target. The window is shown via **SDL2** on Linux/macOS
and the built-in **Win32** driver on Windows.

## What's in this folder

- `main.c` — entry point; loads the UI exported from the project
- `hal.c` / `hal.h` — display and input backend (SDL2 or Win32)
- `lv_conf_sdl.defaults` / `lv_conf_windows.defaults` — per-platform LVGL config overrides
- `CMakeLists.txt` — fetches LVGL, generates `lv_conf.h`, and links the exported `lib-ui`

## How it works

When configured, the simulator automatically:

1. Fetches LVGL via CMake `FetchContent` (version taken from `project.xml`)
2. Generates `lv_conf.h` from the platform-specific `lv_conf_*.defaults`
3. Builds your exported UI as the `lib-ui` library
4. Reads the project name and display size from `project.xml` and passes them to `main.c`

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
