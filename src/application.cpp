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
        mXTexture = mAssetManager.LoadTexture(mConfiguration.GetXPNGPath());
        mOTexture = mAssetManager.LoadTexture(mConfiguration.GetOPNGPath());
        const auto X = GameState::Mark::X;
        const auto O = GameState::Mark::O;
        const auto _ = GameState::Mark::empty;
        mGameState.Position[0][0] = X;
        mGameState.Position[1][1] = O;
        
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

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                //SDL_RenderDrawRect(mRenderer, &mConfiguration.Position[i][j]);
                if (mGameState.Position[i][j] == GameState::Mark::X)
                {
                    SDL_RenderCopy(mRenderer, mXTexture, NULL, &mConfiguration.Position[i][j]);
                }
                else if (mGameState.Position[i][j] == GameState::Mark::O)
                {
                    SDL_RenderCopy(mRenderer, mOTexture, NULL, &mConfiguration.Position[i][j]);
                }
            }
        }
    }

    void Application::Cleanup()
    {
    }

    Application::~Application()
    {
        SDL_DestroyWindow(mWindow);
        SDL_Quit();
    }

}
