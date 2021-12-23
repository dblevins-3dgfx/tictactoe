#pragma once

#include <string>
#include <unordered_map>

struct SDL_Renderer;
struct SDL_Texture;

namespace TTT
{

    class AssetManager
    {
    public:
        explicit AssetManager(SDL_Renderer *renderer = nullptr);
        ~AssetManager();
        SDL_Texture *LoadTexture(const std::string &texturePath);

        void SetRenderer(SDL_Renderer *renderer)
        {
            mRenderer = renderer;
        }

    private:
        SDL_Renderer *mRenderer;
        std::unordered_map<std::string, SDL_Texture*> mTextureStore;
    };

}