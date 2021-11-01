#ifndef __GAME1_H
#define __GAME1_H

#include <string>
#include "common.hpp"
#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

class Game
{
private:
    bool m_bRunning{false};
    SDL_Window *m_pWindow{nullptr};
    SDL_Renderer *m_pRenderer{nullptr};
    SDL_Texture *m_pTexture{nullptr};

    SDL_Rect m_sourceRectangle, m_destinationRectangle;

public:
    Game();
    virtual ~Game();
    bool init(const string nameOfWindow, const int xPos, \
        const int yPos, const int wWidth, const int hHeight, const bool isFullScreen);
    void render();
    void update();
    void handleEvents();
    void clean();
    bool running();
};

#endif