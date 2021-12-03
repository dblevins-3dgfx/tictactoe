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
    SDL_Surface *boardImage = IMG_Load("../assets/images/board.png");
    assert(boardImage != nullptr);

    SDL_Texture *ourPNG = SDL_CreateTextureFromSurface(m_Renderer, boardImage);
    assert(ourPNG != nullptr);

    SDL_FreeSurface(boardImage);

    // Infinite loop for our application
    bool gameIsRunning = true;
    // Main application loop
    while (gameIsRunning)
    {
        SDL_Event event;

        // (1) Handle Input
        // Start our event loop
        while (SDL_PollEvent(&event))
        {
            // Handle each specific event
            if (event.type == SDL_QUIT)
            {
                gameIsRunning = false;
            }
        }
        // (2) Handle Updates

        // (3) Clear and Draw the Screen
        // Gives us a clear "canvas"
        SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0xFF, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(m_Renderer);

        SDL_RenderCopy(m_Renderer, ourPNG, NULL, NULL);

        // Finally show what we've drawn
        SDL_RenderPresent(m_Renderer);
    }

    // And destroy our texture
    SDL_DestroyTexture(ourPNG);

}

Application::~Application()
{
    IMG_Quit();
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
}
