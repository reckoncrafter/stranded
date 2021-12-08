#include "../headers/main.h"

void Window::OnEvent(SDL_Event* Event){
    if(Event->type == SDL_QUIT){
        running = false;
    }
}