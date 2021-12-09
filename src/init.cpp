#include "../headers/main.h"

bool Window::OnInit(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        return false;
    }
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Initialize SDL: %s",
            SDL_GetError());
        return false;
    }
    if (SDL_CreateWindowAndRenderer(window_width, window_height, 0, &window, &renderer) < 0){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Create window and renderer: %s", SDL_GetError());
        return false;
    }
    if (SDL_RenderSetLogicalSize(renderer, 256, 256) < 0){
        return false;
    }

    surface = SDL_LoadBMP("assets/item.bmp");
    item = SDL_CreateTextureFromSurface(renderer, surface);

    surface = SDL_LoadBMP("assets/alert.bmp");
    poi = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);
    return true;
}