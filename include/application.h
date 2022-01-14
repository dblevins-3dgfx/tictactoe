#pragma once

#include <SDL2/SDL.h>

#include "assetmanager.h"
#include "configuration.h"
#include "gamestate.h"

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
        void RenderGame();
        void Cleanup();
        void OnMouseButtonDown(const SDL_MouseButtonEvent& mbe);
        GameState::Mark NextPlayer()
        {
            if (mCurrentPlayer == GameState::Mark::X)
            {
                return GameState::Mark::O;
            }
            else 
            {
                return GameState::Mark::X;
            }
        }

    private:
        AssetManager mAssetManager;

        const Configuration& mConfiguration;
        bool mRunning = false;
        SDL_Window *mWindow;
        SDL_Renderer *mRenderer;
        SDL_Texture *mBoardTexture = nullptr;
        SDL_Texture *mXTexture = nullptr;
        SDL_Texture *mOTexture = nullptr;
        GameState mGameState;
        GameState::Mark mCurrentPlayer = GameState::Mark::X;
    };

}