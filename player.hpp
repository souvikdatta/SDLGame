#ifndef __PLAYER_HPP
#define __PLAYER_HPP

#include "gameobject.hpp"

class Player: public GameObject
{
private:
    // int m_x;
    // int m_y;
    // int m_width;
    // int m_height;

    // int m_CurrentFrame;
    // int m_RowNumber;

    // string m_textureID;
public:
    Player();
    void load (string textureID, int xPos, int yPos, int width, int height);
    void draw(SDL_Renderer *pRenderer);
    void update();
    void clean();
    virtual ~Player();
};

#endif
