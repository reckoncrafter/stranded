#include "../headers/main.h"

void Text::OnWake(){
    for(auto i : root["wake"]){
        cout << i.asString() << endl;
    }
}

void Text::Action(Player &P){
    cout << "> ";
    string playerAct;
    getline(cin, playerAct);
    if(playerAct == "search"){
        if(!SearchedHere){
            int sel = rand()%10;
            switch(sel){
                case 0:
                    cout << root["search"]["food"].asString() << endl;
                    P.Food += 2;
                    break;
                case 1:
                    cout << root["search"]["water"].asString() << endl;
                    P.Water += 1;
                    break;
                case 2 ... 9:
                    cout << root["search"]["nothing"].asString() << endl;
                    break;
            }
            SearchedHere = true;
        }
        else{
            cout << root["search"]["alreadySearched"].asString() << endl;
        }
    }
    else if(playerAct == "status"){
        cout << "Inventory: " << endl;
        cout << "   Food: " << P.Food << '/' << P.maxFood << endl;
        cout << "   Water: " << P.Water << '/' << P.maxWater << endl;
        cout << "   Wood: " << P.Wood << '/' << P.maxWood << endl;
    }
    else{
        cout << "I'm sorry, I don't understand what you want to do.." << endl;
    }
}