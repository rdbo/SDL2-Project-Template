# SDL2-Project-Template
SDL2 Project Template for Windows and Linux
# How to update SDL2 binaries
Source: https://forums.libsdl.org/viewtopic.php?t=9634
1. "Change the SDL2 and SDL2main project settings to use /MT (/MTd for debug) under C++ > Code Generation > Runtime Library. "
2. "Change the SDL2 configuration to Static Library under General > Configuration Type."
3. Add the linker dependencies: version.lib, imm32.lib, winmm.lib, Setupapi.lib
4. Add "#define HAVE_LIBC" on the top of the file SDL_config.windows.h
