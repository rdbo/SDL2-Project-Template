#pragma once
#include "pch.h"

#define SDL_DELAY 0

#define WINDOW_TITLE "SDL Program"
#define WINDOW_POS_X SDL_WINDOWPOS_UNDEFINED
#define WINDOW_POS_Y SDL_WINDOWPOS_UNDEFINED
#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500
#define WINDOW_FLAGS SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN

#define RENDERER_FLAGS 0

namespace Program
{
    extern bool Run;
    extern SDL_Window* Window;
    extern SDL_Renderer* Renderer;
    extern SDL_Color ClearColor;
    void Init();
    void MainLoop();
    void EventHandler();
    void Render();
    void Shutdown();
}