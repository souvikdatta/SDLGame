#include "gameobject.hpp"

void GameObject::draw(SDL_Renderer *pRenderer)
{
    //cout << "GameObject:: Draw called" << "\n";
    TextureManager::getInstance().drawFrame (m_textureID, m_x, m_y, m_width, m_height, \
        pRenderer, m_RowNumber, m_CurrentFrame);
}

void GameObject::update()
{
    m_x += 1;
}

void GameObject::clean()
{
    cout << "GameObject:: clean called" << "\n";
}

void GameObject::load(string textureID, int xPos, int yPos, int width, int height)
{
    // cout << "GameObject:: load called" << "\n";
    m_textureID = textureID;
    m_x = xPos;
    m_y = yPos;
    m_width = width;
    m_height = height;
    m_CurrentFrame = 1;
    m_RowNumber = 1;
}

GameObject::~GameObject()
{

}