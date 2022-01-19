#include <assert.h>

#include <SDL2/SDL_image.h>

#include "application.h"

namespace TTT
{

    Application::Application(const Configuration &config) : mConfiguration(config)
    {
        int initStatus = SDL_Init(SDL_INIT_VIDEO);
        assert(initStatus == 0);

        const int WinPosX = 20;
        const int WinPosY = 20;
        const int WinWidth = 640;
        const int WinHeight = 480;
        mWindow = SDL_CreateWindow("Tic Tac Toe", WinPosX, WinPosY, WinWidth, WinHeight, SDL_WINDOW_SHOWN);
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
    }

    void Application::OnMouseButtonDown(const SDL_MouseButtonEvent &mbe)
    {
        if (mbe.button == SDL_BUTTON_LEFT)
        {
            SDL_Point p;
            p.x = mbe.x;
            p.y = mbe.y;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (mGameState.Position[i][j] == GameState::Mark::empty)
                    {
                        auto r = mConfiguration.Position[i][j];
                        if (SDL_PointInRect(&p, &r) == SDL_TRUE)
                        {
                            mGameState.Position[i][j] = mCurrentPlayer;
                            mCurrentPlayer = NextPlayer();
                        }
                    }
                }
            }
        }
    }

    void Application::HandleInputs()
    {
        SDL_Event event;

        while (SDL_PollEvent(&event) == SDL_TRUE)
        {
            if (event.type == SDL_QUIT)
            {
                Stop();
            }
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                OnMouseButtonDown(event.button);
            }
        }
    }

    void Application::Update()
    {
        mWinner = GameLogic::CheckWinner(mGameState);
    }

    void Application::Render()
    {
        const int red = 0;
        const int green = 0;
        const int blue = 0xff;
        SDL_SetRenderDrawColor(mRenderer, red, green, blue, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(mRenderer);
        RenderGame();
        SDL_RenderPresent(mRenderer);
    }

    void Application::RenderGame()
    {
        SDL_RenderCopy(mRenderer, mBoardTexture, NULL, NULL);

        if (mWinner == GameLogic::Winner::none)
        {
            if (mCurrentPlayer == GameState::Mark::X)
            {
                SDL_RenderCopy(mRenderer, mXTexture, NULL, &mConfiguration.CurrentPlayerIndicator);
            }
            else
            {
                SDL_RenderCopy(mRenderer, mOTexture, NULL, &mConfiguration.CurrentPlayerIndicator);
            }
        }
        else
        {
            if (mWinner == GameLogic::Winner::X)
            {
                SDL_RenderCopy(mRenderer, mXTexture, NULL, NULL);
            }
            else
            {
                SDL_RenderCopy(mRenderer, mOTexture, NULL, NULL);
            }
        }

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
