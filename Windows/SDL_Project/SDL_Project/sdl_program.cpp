#include "pch.h"
#include "sdl_program.h"

//Variables
namespace Program
{
    bool Run;
    SDL_Window* Window;
    SDL_Renderer* Renderer;
    SDL_Color ClearColor = { 55, 55, 55, 255 };
}

//Functions

void Program::MainLoop()
{
    EventHandler();
    SDL_Color CurrentClearColor;
    SDL_GetRenderDrawColor(Renderer, &CurrentClearColor.r, &CurrentClearColor.g, &CurrentClearColor.b, &CurrentClearColor.a);
    if (CurrentClearColor.r != ClearColor.r || CurrentClearColor.g != ClearColor.g || CurrentClearColor.b != ClearColor.b || CurrentClearColor.a != ClearColor.a)
        SDL_SetRenderDrawColor(Renderer, ClearColor.r, ClearColor.g, ClearColor.b, ClearColor.a);
    Render();
    SDL_Delay(SDL_DELAY);
}

void Program::EventHandler()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        Run = false;
    }
}

void Program::Render()
{
    SDL_RenderClear(Renderer);
    SDL_RenderPresent(Renderer);
}

void Program::Init()
{
    Run = SDL_Init(SDL_INIT_EVERYTHING) == 0;
    Window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_POS_X, WINDOW_POS_Y, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_FLAGS);
    Renderer = SDL_CreateRenderer(Window, -1, RENDERER_FLAGS);

    Run == Run && Window && Renderer;

    while (Run)
    {
        MainLoop();
    }

    Shutdown();
}

void Program::Shutdown()
{
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
}