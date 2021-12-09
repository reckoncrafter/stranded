#include "../headers/main.h"
struct Player{
    constrained<int,0,100> saturation = 0;
    constrained<int,0,100> hydration = 0;

    std::array<std::string, 20> inventory{""};
    bool putInInventory(std::string item){
        for(auto &i : inventory){
            if(i == ""){
                i = item;
                return true;
            }
        }
        return false;
    }
};

struct Cache{
    SDL_Point pos;
};

class Text{
public:
    Json::Value messages;
    Json::Value items;
    Text(){
        std::ifstream fin;
        fin.open("assets/messages.json");
        Json::CharReaderBuilder builder;
        Json::String errs;
        bool r = Json::parseFromStream(builder, fin, &messages, &errs);
        if(!r){
            std::cerr << "Error: " << errs;
            return;
        }
        fin.close();
        fin.open("assets/items.json");
        r = Json::parseFromStream(builder,fin,&items,&errs);
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