#include "game.hpp"

Game::Game()
{

}

Game::~Game()
{

}

bool Game::init(const string nameOfWindow, const int xPos, \
    const int yPos, const int wWidth, const int hHeight, \
    const bool isFullScreen)
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


                if (TextureManager::getInstance().load ("assets/animate-alpha.png", \
                    "animate", m_pRenderer) == false)
                {
                    retStatus =  false;
                }

                //Create GameObject and PLayer Object
                m_GameObjects.push_back (new GameObject());
                //Call Load
                m_GameObjects[0]->load ("animate", 100, 100, 128, 82);

                m_GameObjects.push_back (new Player());
                //Call Load
                m_GameObjects[1]->load ("animate", 350, 350, 128, 82);

                //Now loop through the objects and call load functions of respective objects
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

    // TextureManager::getInstance().draw ("animate", 0, 0, 128, 82, m_pRenderer);

    // TextureManager::getInstance().drawFrame ("animate", 100, 100, \
    //     128, 82, m_pRenderer, 1, m_currFrameIndex);

    // m_go.draw (m_pRenderer);
    // m_player.draw (m_pRenderer);

    for(auto &i: m_GameObjects)
        i->draw(m_pRenderer);

    SDL_RenderPresent (m_pRenderer);
}

void Game::update()
{
#if 0
    static unsigned int currTime, lastTime = 0;
    static int index = 0;
    currTime = SDL_GetTicks();
    if(currTime >= lastTime + animDelayInMS)
    {
        //Move the source window in x Axis
        m_currFrameIndex = index++ % 6;
        lastTime = currTime;
        if(index > 6)
            index = 0;
    }
#endif
    // m_go.update();
    // m_player.update();
    for(auto &i: m_GameObjects)
        i->update();

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