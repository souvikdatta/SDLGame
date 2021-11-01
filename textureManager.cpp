#include "textureManager.hpp"


TextureManager& TextureManager::getInstance()
{
    static TextureManager o;
    return o;
}

TextureManager::TextureManager()
{
    //cout << "TExture Manager constructor called" << endl;
}

TextureManager::~TextureManager()
{
    //cout << "TExture Manager destructor called" << endl;
}


bool TextureManager::load (const string nameOfGfxAsset, const string textureID, \
    SDL_Renderer *pRenderer)
{
    bool retStatus = true;
    SDL_Texture *pTempTexture = nullptr;

    SDL_Surface *pTempSurface = IMG_Load (nameOfGfxAsset.c_str());
    if(pTempSurface)
    {   
        pTempTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);

        // Free the temp Surface as you donot need the Surface any more as 
        // it has already been mapped
        SDL_FreeSurface (pTempSurface);
        
        if(pTempTexture)
        {
            //Save the created texture in Map against the texture id
            m_textureMap.insert(make_pair(textureID, pTempTexture));
        }
        else
        {
            cout << "Unable to create texture  from Surface:" << "\n";
            retStatus = false;
        }
    }
    else
    {
       cout << "Unable to create temp Surface from asset:" << nameOfGfxAsset << "\n";
       retStatus = false;
    }

    return retStatus;
}

//draw
void TextureManager::draw (const string textureID, const int xPos, \
        const int yPos, const int width, const int height, \
        SDL_Renderer *pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect sRect, dRect;
    sRect.x = 0;
    sRect.y = 0;
    sRect.w = dRect.w = width;
    sRect.h = dRect.h = height;

    dRect.x = xPos;
    dRect.y = yPos;

    SDL_RenderCopyEx (pRenderer, m_textureMap[textureID], &sRect, &dRect, 0, 0, flip);
}


//drawFrame - This is to be used when the sprite strip has multiple rows
void TextureManager::drawFrame (const string textureID, const int xPos, \
    const int yPos, const int width, const int height, \
    SDL_Renderer *pRenderer, const int rowIndex, const int currFrameIndex, \
    SDL_RendererFlip flip)
{
    SDL_Rect sRect, dRect;
    sRect.x = width * currFrameIndex;
    sRect.y = height * (rowIndex - 1);
    sRect.w = dRect.w = width;
    sRect.h = dRect.h = height;

    dRect.x = xPos;
    dRect.y = yPos;
    SDL_RenderCopyEx (pRenderer, m_textureMap[textureID], &sRect, &dRect, 0, 0, flip);
}