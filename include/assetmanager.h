#pragma once

#include <assert.h>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace TTT
{

    class AssetManager
    {
    public:

        SDL_Texture *LoadTexture(SDL_Renderer *renderer, const std::string &texturePath)
        {
            SDL_Surface *surface = IMG_Load(texturePath.c_str());
            assert(surface != nullptr);

            SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
            assert(texture != nullptr);

            SDL_FreeSurface(surface);
            return texture;
        }

        void UnloadTexture(SDL_Texture *texture)
        {
            SDL_DestroyTexture(texture);
        }

    private:

    };

}