#include "../headers/main.h"

void Window::OnEvent(SDL_Event* Event, Player* player){
    switch(Event->type){
        case SDL_QUIT:
            running = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            click = {Event->motion.x, Event->motion.y};
            //std::cout << CalculateDistance(player->position, click) << "km away" << std::endl;
            for(auto it : items){
                SDL_Rect r = {it.pos.x, it.pos.y, 8, 8};
                if(SDL_PointInRect(&click, &r)){
                    std::cout << "This cache is " << CalculateDistance(player->position, it.pos) << " pixels away" << std::endl;
                    std::cout << "Type 'go' to travel" << std::endl;
                    player->canTravel = true;
                    player->desiredLocation = it.pos;
                    player->isNearCache = true;
                }
            }
            if(!player->canTravel){
                std::cout << "This point is " << CalculateDistance(player->position, click) << " pixels away" << std::endl;
                std::cout << "Type 'go' to travel" << std::endl;
                player->canTravel = true;
                player->desiredLocation = click;
                player->isNearCache = false;
            }
            break;
    }
}