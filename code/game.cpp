// #include<iostream>
// //#include<stdlib.h>

// #include"character.hpp"
// #include"dungeon.hpp"
#include"game.hpp"


void gameover() {
    std::cout << "You died!\nGAMEOVER!" << std::endl;
    exit(0);
}

int main() 
{
    try{
        //---------------------------------main logic-----------------------//
        int mapLength = 20;
        Character player = Character("Petetra", "Warrior");
        Dungeon dungeon = Dungeon(player); //paul: originally had maplength as an argument
        dungeon.dungeonStart();
        
        
        //---------------------------------end main logic-----------------------//
    } catch(...)
    {
        std::cout << "something went wrong.";
    }
    //Paul: should we put the bits with the art printouts and the story blurbs here or in dungeon?
    return 0;
}




