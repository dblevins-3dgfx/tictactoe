#include <assert.h>

#include <SDL2/SDL_image.h>

#include "application.h"

namespace TTT
{

    Application::Application(const Configuration &config) : mConfiguration(config)
    {
        int initStatus = SDL_Init(SDL_INIT_VIDEO);
        assert(initStatus == 0);

        mWindow = SDL_CreateWindow("Tic Tac Toe", 20, 20, 640, 480, SDL_WINDOW_SHOWN);
        assert(mWindow != nullptr);

        mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
        assert(mRenderer != nullptr);

        mAssetManager.SetRenderer(mRenderer);
    }

    void Application::Run()
    {
        Init();

        mRunning = true;
        while (IsRunning())
        {
            HandleInputs();
            Update();
            Render();
        }

        Cleanup();
    }

    void Application::Init()
    {
        mBoardTexture = mAssetManager.LoadTexture(mConfiguration.GetBoardPNGPath());
    }

    void Application::HandleInputs()
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                Stop();
            }
        }
    }

    void Application::Render()
    {
        SDL_SetRenderDrawColor(mRenderer, 0, 0, 0xFF, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(mRenderer);
        RenderGame();
        SDL_RenderPresent(mRenderer);
    }

    void Application::RenderGame()
    {
        SDL_RenderCopy(mRenderer, mBoardTexture, NULL, NULL);
    }

    void Application::Cleanup()
    {
        mAssetManager.UnloadTexture(mBoardTexture);
    }

    Application::~Application()
    {
        SDL_DestroyWindow(mWindow);
        SDL_Quit();
    }

}
