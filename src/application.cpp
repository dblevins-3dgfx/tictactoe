#include <assert.h>

#include <SDL2/SDL_image.h>

#include "application.h"

namespace TTT
{

    Application::Application(SDL::SDLShim& shim, const Configuration &config) : mSDL(shim), mConfiguration(config)
    {
        int initStatus = mSDL.Init(SDL_INIT_VIDEO);
        assert(initStatus == 0);

        mWindow = mSDL.CreateWindow("Tic Tac Toe", 20, 20, 640, 480, SDL_WINDOW_SHOWN);
        assert(mWindow != nullptr);

        mRenderer = mSDL.CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
        assert(mRenderer != nullptr);

        int flags = IMG_INIT_PNG;
        initStatus = IMG_Init(flags);
        assert((initStatus & flags) == flags);
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
        SDL_Surface *boardSurface = IMG_Load(mConfiguration.GetBoardPNGPath().c_str());
        assert(boardSurface != nullptr);

        mBoardTexture = SDL_CreateTextureFromSurface(mRenderer, boardSurface);
        assert(mBoardTexture != nullptr);

        SDL_FreeSurface(boardSurface);
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
        SDL_RenderCopy(mRenderer, mBoardTexture, NULL, NULL);
        SDL_RenderPresent(mRenderer);
    }

    void Application::Cleanup()
    {
        SDL_DestroyTexture(mBoardTexture);
    }

    Application::~Application()
    {
        IMG_Quit();
        SDL_DestroyWindow(mWindow);
        SDL_Quit();
    }

}
