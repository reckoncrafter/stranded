#include "../headers/main.h"



void Window::OnRender(){
    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_RenderFillRect(renderer, NULL);

    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    
    /*
    for(int i = 0; i < HM_SIZE; i++){
        int y1 = 0;
        int y2 = window_height;
        int x1 = (window_width / HM_SIZE) * i+1;
        int x2 = x1;
        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    }
    for(int i = 0; i < HM_SIZE; i++){
        int x1 = 0;
        int x2 = window_width;
        int y1 = (window_height / HM_SIZE) * i+1;
        int y2 = y1;
        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    }
    */
    
    for(int y = 0; y < HM_SIZE; y++){
        for(int x = 0; x < HM_SIZE; x++){
            SDL_Rect R;
            R.h = 1;
            R.w = 1;
            R.x = x;
            R.y = y;
            SDL_Color c;
            if(hm[x][y] < 0.4){
                c = ocean;
            }
            else if(hm[x][y] < 0.45){
                c = sand;
            }
            else if(hm[x][y] < 0.8){
                c = grass;
            }
            else if(hm[x][y] < 1.0){
                c = snow;
            }
            SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
            SDL_RenderFillRect(renderer, &R);
        }
    }
}