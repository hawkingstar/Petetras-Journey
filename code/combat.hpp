#pragma once

#include<string>
#include<iostream> //does this have good reading functionality?
// #include<stdlib.h>
#include<random> //Paul: does this have the same usefullness of java's random?
// #include<cstdlib> //or this? The way it works is kinda weird
// #include<cstring>

//using namespace std;

#include"character.hpp"
#include"monster.hpp"
#include "dungeon.hpp"
//#include"general.hpp"
//for lowercasing strings

class Combat 
{
private://paul: I'm making this bit private right now but it might change later. 
    Character player;
    //Monster enemy;
    int turnCount;
    std::string choice;
    Monster enemy;

    /**
     * Creates a combat situation with the given player and enemy
     * @param player The player in the combat situation
     * @param enemy The enemy in the combat situation
     */
    
public:
    Combat(Character jugador, Monster enemigo);
    /**
     * Put this into Dungeon class
     */

    //Paul: should we?
    void startFight();
};