#include "../headers/main.h"

#define NUM_ITEMS 8
#define NUM_POIS 2

SDL_Point placeLocation(double hm[HM_SIZE][HM_SIZE]){
    while(true){
        int x = rand()%HM_SIZE;
        int y = rand()%HM_SIZE;
        if(hm[x][y] < 0.4){
            continue;
        }
        return {x,y};
    }
    return {0,0};
}

Json::Value* GetJson(std::string filename){
    Json::Value* j = new Json::Value;
    std::ifstream fin;
    fin.open(filename);
    Json::CharReaderBuilder builder;
    Json::String errs;
    bool r = Json::parseFromStream(builder, fin, j, &errs);
    if(!r){
        std::cerr << "Error: " << errs;
        return nullptr;
    }
    fin.close();
    return j;
}

int main(){
    srand(time(NULL));
    Window map;
    Text text;
    Player player;

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

    if(player.position.x == 0 && player.position.y == 0){
        player.position = placeLocation(map.hm);
    }

    Cache items[NUM_ITEMS];
    SDL_Point pois[NUM_POIS];


    // TODO: Read in locaiton values from state.json
    for(int i = 0; i < NUM_ITEMS; i++){
        items[i].pos = placeLocation(map.hm);
    }
    for(int i = 0; i < NUM_POIS; i++){
        pois[i] = placeLocation(map.hm);
    }

    text.OnWake();

    SDL_Event Event;
    while(map.running){
        usleep(SPEED_LIMITER);
        while(SDL_PollEvent(&Event)){
            map.OnEvent(&Event);
        }
        
        map.OnRender();
        // Additional Rendering
        // Icons
        for(int i = 0; i < NUM_ITEMS; i++){
            SDL_Rect R;
            R.h = 8;
            R.w = 8;
            R.x = items[i].pos.x;
            R.y = items[i].pos.y;
            SDL_RenderCopy(map.renderer, map.item, NULL, &R);
        }
        for(int i = 0; i < NUM_POIS; i++){
            SDL_Rect R;
            R.h = 8;
            R.w = 8;
            R.x = pois[i].x;
            R.y = pois[i].y;
            SDL_RenderCopy(map.renderer, map.poi, NULL, &R);
        }

        // Crosshairs
        SDL_SetRenderDrawColor(map.renderer, 255, 0, 0, 255);
        SDL_RenderDrawLine(map.renderer, player.position.x, 0, player.position.x, map.window_height);
        SDL_RenderDrawLine(map.renderer, 0, player.position.y, map.window_width, player.position.y);

        //
        SDL_RenderPresent(map.renderer);
        if(!text.Action(player)){
            std::ofstream fout;
            Json::StreamWriterBuilder builder;
            builder["indentation"] = " ";
            Json::StreamWriter* writer(builder.newStreamWriter());
            fout.open("assets/state.json");

            Json::Value newstate;
            newstate["player"]["x"] = player.position.x;
            newstate["player"]["y"] = player.position.y;
            newstate["player"]["saturation"] = (int)player.saturation;
            newstate["player"]["hydration"] = (int)player.hydration;

            for(int i = 0; i < NUM_ITEMS; i++){
                newstate["items"]["x"].append(items[i].pos.x);
                newstate["items"]["y"].append(items[i].pos.y);
            }
            for(int i = 0; i < NUM_POIS; i++){
                newstate["pois"]["x"].append(pois[i].x);
                newstate["pois"]["y"].append(pois[i].y);
            }
            writer->write(newstate, &fout);

            fout << endl; // don't even try asking me why this is required, just DON'T FUCKING MOVE IT

            exit(EXIT_SUCCESS);
        }
        SDL_RenderClear(map.renderer);
    }
}