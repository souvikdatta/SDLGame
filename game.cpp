#include "game.hpp"

Game::Game()
{

}

Game::~Game()
{

}

bool Game::init(const string nameOfWindow, const int xPos, \
    const int yPos, const int wWidth, const int hHeight, const bool isFullScreen)
{
    bool retStatus = true;

    m_bRunning = true;

    if(! SDL_Init(SDL_INIT_EVERYTHING))
    {
        cout << "SDL Init successful" << endl;
        //create window
        m_pWindow = SDL_CreateWindow (nameOfWindow.c_str(), xPos, yPos, wWidth, hHeight, 0);
        if(m_pWindow != nullptr)
        {
            //create renderer
            m_pRenderer = SDL_CreateRenderer (m_pWindow, -1, SDL_RENDERER_ACCELERATED);
            if(nullptr == m_pRenderer)
            {
                retStatus =  false;
                cout << "Failed to create Renderer" << endl;
            }
            else
            {
                //Set render color
                SDL_SetRenderDrawColor (m_pRenderer, 255, 0, 0, 255);

                //Load the assets
                SDL_Surface *pTempSurface = SDL_LoadBMP ("assets/rider.bmp");
                if(pTempSurface)
                {
                    //From the Surface, we create a Texture
                    m_pTexture = SDL_CreateTextureFromSurface (m_pRenderer, pTempSurface);
                    if(m_pTexture)
                    {
                        //Free the Surface as I donot need the Surface any more - why?
                        //Because I have already created a Texture from the Surface
                        SDL_FreeSurface (pTempSurface);

                        SDL_QueryTexture (m_pTexture, NULL, NULL, \
                            &m_sourceRectangle.w, &m_sourceRectangle.h);

                        //Now setting the position and size of dest rect according to source rect
                        // m_destinationRectangle.x = m_sourceRectangle.x = 0;
                        // m_destinationRectangle.y = m_sourceRectangle.y = 0;
                        // m_destinationRectangle.w = m_sourceRectangle.w = 50;
                        // m_destinationRectangle.h = m_sourceRectangle.h = 50;

                        m_sourceRectangle.x = 50;
                        m_sourceRectangle.y = 50;
                        m_destinationRectangle.x=50;
                        m_destinationRectangle.y=50;

                        m_sourceRectangle.w = 50;
                        m_sourceRectangle.h = 50;

                        m_destinationRectangle.w = 100;
                        m_destinationRectangle.h = 100;

                    }
                    else
                    {
                        retStatus =  false;
                        cout << "Unable to create Texture from Surface" << endl;
                    }   
                }
                else
                {
                    retStatus =  false;
                    cout << "Unable to create Surface" << endl;
                }
            }
        }
        else 
        {
            retStatus =  false;
            cout << "Failed to create SDL window" << endl;
        }
    }
    else 
    {
        retStatus =  false;
        cout << "Failed to do SDL Init" << endl;
    }

    return retStatus;
}

void Game::render()
{
    SDL_RenderClear (m_pRenderer);

    //Draw the Texture to the window
    // SDL_RenderCopy (m_pRenderer, m_pTexture, \
        &m_sourceRectangle, &m_destinationRectangle);

    SDL_RenderCopy (m_pRenderer, m_pTexture, \
        &m_sourceRectangle, &m_destinationRectangle);


    SDL_RenderPresent (m_pRenderer);
}

void Game::update()
{

}

void Game::handleEvents()
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                m_bRunning = false;
                break;
            default:
                // cout << "Default case" << event.type << "\n";
            break;
        }
    }
}

void Game::clean()
{
    cout << "SDL environment cleaned" << endl;
    SDL_DestroyWindow (m_pWindow);
    SDL_DestroyRenderer (m_pRenderer);
    SDL_Quit ();
}

bool Game::running()
{
    return m_bRunning;
}