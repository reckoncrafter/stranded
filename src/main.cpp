#include "../headers/main.h"
using namespace std;

SDL_Point placeLocation(double hm[HM_SIZE][HM_SIZE]){
    while(true){
        int x = rand()%HM_SIZE;
        int y = rand()%HM_SIZE;
        if(hm[x][y] < 0.4){
            cout << hm[x][y] << endl;
            continue;
        }
        return {x,y};
    }
    return {0,0};
}

int main(){
    srand(time(NULL));
    Window map;

    if(map.OnInit() == false){
        return -1;
    }

    const siv::PerlinNoise::seed_type seed = 123456u;
    const siv::PerlinNoise perlin{ seed };

	for (int y = 0; y < HM_SIZE; ++y){
		for (int x = 0; x < HM_SIZE; ++x){
			const double noise = perlin.octave2D_01((x * 0.01), (y * 0.01), 6);
            map.hm[x][y] = noise;
		}
	}

    SDL_Point Montressor = placeLocation(map.hm);
    cout << Montressor.x << ", " << Montressor.y << endl;


    SDL_Event Event;
    while(map.running){
        usleep(SPEED_LIMITER);
        while(SDL_PollEvent(&Event)){
            map.OnEvent(&Event);
        }
        
        map.OnRender();
        // Additional Rendering
        SDL_SetRenderDrawColor(map.renderer, 255, 0, 0, 255);
        SDL_RenderDrawPoint(map.renderer, Montressor.x, Montressor.y);
        //
        SDL_RenderPresent(map.renderer);
        SDL_RenderClear(map.renderer);
    }
}