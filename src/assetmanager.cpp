#include "assetmanager.h"

#include <assert.h>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace TTT
{

    AssetManager::AssetManager(SDL_Renderer *renderer) : mRenderer(renderer)
    {
        int flags = IMG_INIT_PNG;
        int initStatus = IMG_Init(flags);
        assert((initStatus & flags) == flags);
    }

    AssetManager::~AssetManager()
    {
        for (auto pair : mTextureStore)
        {
            SDL_DestroyTexture(pair.second);
        }
        IMG_Quit();
    }

    SDL_Texture *AssetManager::LoadTexture(const std::string &texturePath)
    {
        SDL_Texture *texture = nullptr;

        auto textureStoreItr = mTextureStore.find(texturePath);

        if (textureStoreItr != mTextureStore.end())
        {
            texture = textureStoreItr->second;
        }
        else
        {
            SDL_Surface *surface = IMG_Load(texturePath.c_str());
            assert(surface != nullptr);

            texture = SDL_CreateTextureFromSurface(mRenderer, surface);
            assert(texture != nullptr);

            SDL_FreeSurface(surface);
            mTextureStore[texturePath] = texture;
        }

        return texture;
    }

}