#include "../headers/main.h"

struct Cache{
    SDL_Point pos;
};

class Window{
public:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;
    SDL_Point click;

    const int window_height = 1024;
    const int window_width = 1024;

    SDL_Color ocean = {65, 101, 138, 255};
    SDL_Color sand = {248, 230, 186, 255};
    SDL_Color grass = {121, 180, 115, 255};
    SDL_Color snow = {199, 199, 204, 255};

    SDL_Texture* item;
    SDL_Texture* poi;

    Cache items[NUM_ITEMS];
    SDL_Point pois[NUM_POIS];

public:
    bool running = true;

    // heightmap
    double hm[HM_SIZE][HM_SIZE];

    int CalculateDistance(SDL_Point a, SDL_Point b){
        // Basic Distance Formula
        // sqrt( (x2-x1)^2 + (y2-y1)^2 )
        int x_dist = b.x - a.x;
        int y_dist = b.y - a.y;
        x_dist *= x_dist;
        y_dist *= y_dist;
        return sqrt(x_dist + y_dist);
    }

    bool OnInit();
    void OnEvent(SDL_Event* Event, Player* player);
    void OnLoop();
    void OnRender();
    void OnCleanup();
};