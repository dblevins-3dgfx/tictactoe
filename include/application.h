#pragma once

#include <SDL2/SDL.h>

#include <configuration.h>

namespace TTT
{

    class Application
    {
    public:
        Application(const Configuration& config);
        ~Application();

        void Run();
        bool IsRunning() { return mRunning; }
        void Stop() { mRunning = false; }

    private:
        void Init();
        void HandleInputs();
        void Update() {} //NOP for now
        void Render();
        void Cleanup();

    private:
        const Configuration& mConfiguration;
        bool mRunning = false;
        SDL_Window *mWindow;
        SDL_Renderer *mRenderer;
        SDL_Texture *mBoardTexture = nullptr;
    };

}