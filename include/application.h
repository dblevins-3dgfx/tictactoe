#pragma once

#include <SDL2/SDL.h>

class Application
{
public:
    Application();
    ~Application();

    void Run();

private:
    SDL_Window* m_Window;
    SDL_Renderer *m_Renderer;
};
