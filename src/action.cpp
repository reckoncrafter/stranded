#include "../headers/main.h"

void Text::OnWake(){
    for(auto i : messages["wake"]){
        cout << i.asString() << endl;
    }
}

bool Text::Action(Player &P){
    cout << "> ";
    string playerAct;
    getline(cin, playerAct);

    
    if(
        playerAct == "search" || 
        playerAct == "look"
    ){

        if(!SearchedHere){
            int sel = rand()%2; // 10
            switch(sel){
                case 0:
                    cout << messages["search"]["food"].asString() << endl;
                    P.putInInventory("alien_berry");
                    break;
                case 1:
                    cout << messages["search"]["water"].asString() << endl;
                    P.putInInventory("unsafe_water");
                    break;
                /*
                case 2 ... 9:
                    cout << messages["search"]["nothing"].asString() << endl;
                    break;
                */
            }
            //SearchedHere = true;
        }
        else{
            cout << messages["search"]["alreadySearched"].asString() << endl;
        }
    }

    else if(playerAct == "status"){
        cout << "Saturation: " << (int)P.saturation << endl;
        cout << "Hydration: " << (int)P.hydration << endl;
    }

    else if(playerAct == "inventory"){
        for(auto i : P.inventory){
            if(i == ""){
                cout << "[ ]" << endl;
            }
            else{
                try{
                    cout << "[" << items[i]["name"].asString() << "]" << endl;
                }
                catch(Json::RuntimeError){
                    cout << "[ ERROR ]" << endl;
                }
            }
        }
    }


    else if(playerAct == "quit"){
        cout << messages["quit"].asString() << endl;
        return false;
    }
    else{
        cout << "I'm sorry, I don't understand what you want to do.." << endl;
    }
    return true;
}