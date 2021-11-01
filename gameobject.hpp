#ifndef __GAMEOBJECT_HPP
#define __GAMEOBJECT_HPP
#include <SDL2/SDL.h>
#include "textureManager.hpp"

#include <iostream>

using namespace std;

class GameObject
{
private:

protected:
    int m_x;
    int m_y;
    int m_width;
    int m_height;

    int m_CurrentFrame;
    int m_RowNumber;

/*
    unsigned int m_lastTime{0};
    int m_AnimIndex{0};
*/
    string m_textureID;

public:
    virtual void load (string textureID, int xPos, int yPos, int width, int height);
    virtual void draw(SDL_Renderer *pRenderer);
    virtual void update();
    virtual void clean();

    virtual ~GameObject();
};

#endif