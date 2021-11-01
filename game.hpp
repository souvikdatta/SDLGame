#ifndef __GAME1_H
#define __GAME1_H

#include <string>
#include "common.hpp"
#include "textureManager.hpp"
#include "gameobject.hpp"
#include "player.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

using namespace std;

static constexpr unsigned int animDelayInMS = 100;

class Game
{
private:
    bool m_bRunning{false};
    SDL_Window *m_pWindow{nullptr};
    SDL_Renderer *m_pRenderer{nullptr};
    SDL_Texture *m_pTexture{nullptr};
    SDL_Rect m_sourceRectangle, m_destinationRectangle;
    int m_currFrameIndex{0};
    GameObject *m_pGo;
    Player *m_pPlayer;

    vector<GameObject *> m_GameObjects;

public:
    Game();
    virtual ~Game();
    bool init(const string nameOfWindow, const int xPos, \
        const int yPos, const int wWidth, const int hHeight, \
        const bool isFullScreen);
    void render();
    void update();
    void handleEvents();
    void clean();
    bool running();
};

#endif