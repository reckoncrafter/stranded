#include "../headers/main.h"
class Window{
public:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;

    const int window_height = 1024;
    const int window_width = 1024;

    SDL_Color ocean = {65, 101, 138, 255};
    SDL_Color sand = {248, 230, 186, 255};
    SDL_Color grass = {121, 180, 115, 255};
    SDL_Color snow = {199, 199, 204, 255};

public:
    bool running = true;

    // heightmap
    double hm[HM_SIZE][HM_SIZE];

    bool OnInit();
    void OnEvent(SDL_Event* Event);
    void OnLoop();
    void OnRender();
    void OnCleanup();
};