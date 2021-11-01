#ifndef __TEXTURE_MANAGER_HPP
#define __TEXTURE_MANAGER_HPP

#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

class TextureManager
{
private:
    //This will hold the mapping between the Texture ID and
    //actutal Texture (mapped to the GFX asset)
    map<string, SDL_Texture*> m_textureMap;

    TextureManager();
public:

    //Load
    bool load (const string nameOfGfxAsset, const string textureID, \
        SDL_Renderer *pRenderer);

    //draw
    void draw (const string textureID, const int xPos, \
        const int yPos, const int width, const int height, \
        SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    //drawFRame
    void drawFrame (const string textureID, const int xPos, \
    const int yPos, const int width, const int height, \
    SDL_Renderer *pRenderer, const int rowIndex, const int currFrameIndex, \
    SDL_RendererFlip flip = SDL_FLIP_NONE);

    static TextureManager& getInstance();
    virtual ~TextureManager();
};

#endif