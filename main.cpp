#include <iostream>
#include "Game.hpp"



int main(){

    //init srand
    std::srand(static_cast<unsigned>(time(NULL)));

    Game game;


    while(game.getWinIsOpen()){
        
        game.update();

        game.render();

    }

    return 0;
}