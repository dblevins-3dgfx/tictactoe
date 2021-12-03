#pragma once

#include <SDL2/SDL.h>

class Application
{
public:
    Application();
    ~Application();

    void Run();

private:
    void Init();
    void HandleInputs();
    void Update() {} //NOP for now
    void Render();
    void Cleanup();

private:
    bool mRunning = true;
    SDL_Window* m_Window;
    SDL_Renderer *m_Renderer;
    SDL_Texture *mBoardTexture = nullptr;
};
