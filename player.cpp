#include "player.hpp"

void Player::draw(SDL_Renderer *pRenderer)
{
    // cout << "Player:: Draw called" << "\n";
    GameObject::draw(pRenderer);
}

void Player::update()
{
    // cout << "Player:: update called" << "\n";
    m_x -= 1;   
}

void Player::clean()
{
    // cout << "Player:: clean called" << "\n";
    GameObject::clean();
}

void Player::load(string textureID, int xPos, int yPos, int width, int height)
{
    // cout << "Player:: laod called" << "\n";
    GameObject::load (textureID, xPos, yPos, width, height);
}

Player::Player()
{

}

Player::~Player()
{
    
}