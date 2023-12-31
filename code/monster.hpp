#pragma once

#include<iostream>
// #include<stdlib.h>
// #include<string.h>
#include<string>
// #include<stdio.h>
// #include<cstring>
#include<random> //Paul: does this have the same usefullness of java's random?
// #include<cstdlib> //or this? The way it works is kinda weird
#include<stdexcept>

//using namespace std;

//#include"character.cpp" 
//Paul: probably unnecessary this one, but for some reason it makes 
//including string.hpp possible below. 

//#include"item.hpp"
#include"armor.hpp"
#include"defense.hpp"
#include"offense.hpp"
//#include<boost/algorithm/string.hpp>//for lowercasing strings
    //Ethan: commented out since it seemed to break the include path


#include <iostream>
#include <string>

//----------------------------------------------------------------------------//

class Monster {
private: 
    std::string name;
    int hp;
    int maxHp;
    int mp;
    int maxMp;
    int speed;
public:
     // speed is on a scale of 0-20
    Offense offense;
    Defense defense;
    Armor armor;
    int block = 0;
    bool isAlive = true;
    
    Monster(std::string name="", int hp=0, int mp=0, int speed=0, Offense offense=Offense("Placeholder", 0), 
    Defense defense=Defense("Placeholder", 0), Armor armor=Armor("Placeholder", 0));

    std::string getname();
    int gethp();
    int getmaxHp();
    int getmp();
    int getmaxMp();
    int getspeed();
    
    


    /* --------------------------------- Attack --------------------------------- */
    /**
     * This method prints out the monster's attack statement and returns the value
     * of their attack.
     *
     * @return Attack Damage
     */
    int attack();

    /* --------------------------------- Defend --------------------------------- */
    /**
     * This method prints out the character's defend statement and sets their block
     * accordingly.
     */
    void defend();

    /* ------------------------------- Take Damage ------------------------------ */
    /**
     * This method subtracts how much damage the character took (accounting for
     * armor) from their HP and then checks if they are dead.
     *
     * @param damage Damage to subtract
     */
    void takeDamage(int damage);

    /* ---------------------------------- Heal ---------------------------------- */
    /**
     * This method adds the inputted value to the HP of the character, maxing out at
     * maxHp.
     *
     * @param healValue How much HP the character heals.
     */
    void heal(int healValue);

    /* --------------------------------- Restore -------------------------------- */
    /**
     * This method adds the inputted value to the MP of the character, maxing out at
     * maxMP.
     *
     * @param manaValue How much MP the character recovers.
     */
    void restore(int manaValue);

    /* ------------------------------- Check Dead ------------------------------- */
    /**
     * Checks if the character is dead.
     */
    bool checkAlive();

    /* ------------------------------- Get Monster ------------------------------ */

    /**
     * This method creates a new monster based on the given name.
     *
     * @deprecated Use getMonster(int name) instead.
     * @param name
     * @return Monster instance created
     * @throws IllegalArgumentException throws error if given name is not valid
     *
     */
    static Monster getMonster(std::string name);

    static Monster getMonster(int floor);

    /* ------------------------------ Random Action ----------------------------- */
    /**
     * This method randomly decides whether the monster attacks or defends and
     * returns the attack value if they are attacking.
     * If defending, the returned value is 0.
     *
     * @return damage done by monster
     */
    int randomAction();
};
