#include "../headers/main.h"
struct Player{
    int maxFood = 20;
    int maxWood = 200;
    int maxWater = 10;

    int Food = 0;
    int Water = 0;
    int Wood = 0;
};

struct Item{
    SDL_Point pos;
    int Food;
    int Water;
    int Wood;

    Item(){
        Food = rand()% 8;
        Water = rand()% 3;
        Wood = rand()% 20;
    }
};

class Text{
public:
    Json::Value root;
    Text(){
        std::ifstream fin;
        fin.open("assets/messages.json");
        Json::CharReaderBuilder builder;
        Json::String errs;
        bool r = Json::parseFromStream(builder, fin, &root, &errs);
        if(!r){
            std::cerr << "Error: " << errs;
            return;
        }
    }
    
    // Status flags
    bool SearchedHere = false;


    void OnWake();
    void Action(Player &P);
};