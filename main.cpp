#include "game.hpp"
#include <memory>


using namespace std;

int main()
{
    std::shared_ptr<Game> pGameObj = std::shared_ptr<Game>(new Game());
    //Init the game
    if(pGameObj->init("Chap 1", 100, 100, 640, 480, false) == false)
        return 1;
    
    while(pGameObj->running())
    {
        pGameObj->handleEvents();
        pGameObj->update();
        pGameObj->render();
    }

    pGameObj->clean();

    return 0;
}
