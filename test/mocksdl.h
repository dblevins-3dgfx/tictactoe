#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "sdlshim.h"

/// Dummy definition of SDL_Window for use in mocking.
struct SDL_Window
{
    int dummy = 0;
};

struct SDL_Renderer
{
    int dummy = 0;
};

class MockSDL : public SDL::SDLShim
{
public:
    MOCK_METHOD(int, Init, (uint32_t flags), (override));
    MOCK_METHOD(SDL_Window *, CreateWindow, (const char *title, int x, int y, int w, int h, Uint32 flags), (override));
    MOCK_METHOD(SDL_Renderer *, CreateRenderer, (SDL_Window * window, int index, Uint32 flags), (override));

    SDL_Window dummySdlWindow;
    SDL_Renderer dummySdlRenderer;
};
