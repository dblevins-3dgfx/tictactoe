#include <assert.h>

#include <SDL2/SDL_image.h>

#include "application.h"

Application::Application()
{
    int initStatus = SDL_Init(SDL_INIT_VIDEO);
    assert(initStatus == 0);

    m_Window = SDL_CreateWindow("Tic Tac Toe", 20, 20, 640, 480, SDL_WINDOW_SHOWN);
    assert(m_Window != nullptr);

    m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
    assert(m_Renderer != nullptr);

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
    SDL_Surface *boardImage = IMG_Load("../assets/images/board.png");
    assert(boardImage != nullptr);

    mBoardTexture = SDL_CreateTextureFromSurface(m_Renderer, boardImage);
    assert(mBoardTexture != nullptr);

    SDL_FreeSurface(boardImage);
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
    SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0xFF, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(m_Renderer);
    SDL_RenderCopy(m_Renderer, mBoardTexture, NULL, NULL);
    SDL_RenderPresent(m_Renderer);
}

void Application::Cleanup()
{
    SDL_DestroyTexture(mBoardTexture);
}

Application::~Application()
{
    IMG_Quit();
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
}
