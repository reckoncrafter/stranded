#include "../headers/main.h"
struct Player{
    constrained<int,0,100> saturation = 0;
    constrained<int,0,100> hydration = 0;
    SDL_Point position;

    SDL_Point desiredLocation;
    bool canTravel = false;
    bool isNearCache = false;

    Json::Value state;

    std::array<std::string, 20> inventory{""};

    Player(){
        state = *GetJson("assets/state.json");
        saturation = state["player"]["saturation"].asInt();
        hydration =  state["player"]["hydration"].asInt();
        position.x = state["player"]["x"].asInt();
        position.y = state["player"]["y"].asInt();
    }
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

class Text{
public:
    Json::Value messages;
    Json::Value items;
    Text(){
        messages = *GetJson("assets/messages.json");
        items = *GetJson("assets/items.json");
    }
    
    // Status flags
    bool SearchedHere = false;


    void OnWake();
    bool Action(Player &P);
};