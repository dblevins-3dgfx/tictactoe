#pragma once

#include <SDL2/SDL.h>

namespace SDL
{

    class SDLShim
    {
    public:
        virtual int Init(uint32_t flags)
        {
            return SDL_Init(flags);
        }

        virtual SDL_Window *CreateWindow(const char *title,
                                         int x, int y, int w,
                                         int h, Uint32 flags)
        {
            return SDL_CreateWindow(title, x, y, w, h, flags);
        }

        virtual SDL_Renderer *CreateRenderer(SDL_Window *window, int index, Uint32 flags)
        {
            return SDL_CreateRenderer(window, index, flags);
        }
    };

}