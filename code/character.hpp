#pragma once

//this had some definition ifs, ifndef character in the cpp file

#include<string>
#include<iostream>

//#include"general.hpp"
//#include"game.cpp" //Ethan: commented this out since game includes character.cpp
//Paul: more of these may be needed

//using namespace std;
    //Ethan: commented out namespace since professor mentioned it can cause problems 
    //in large projects

class Character
{

private: 
    int block;//Paul: putting this here since access identifiers are a bit confusing rn
    std::string name;
    int hp;
    int maxHp;
    int mp;
    int maxMp;
    int speed;
public:
    int gethp();
    int getmaxHp();
    int getmp();
    int getmaxMp();
    int getspeed();
    int attackValue;
    bool hasKeyItem;
    bool hasBossKey;
    std::string getname();
    std::string className;
    /* -------------------------------------------------------------------------- */
    
    /* -------------------------------------------------------------------------- */
    //Offense offense; //Ethan: not yet implemented-----------------------------------------
    //Defense defense;
    //Armor armor;
    /* -------------------------------------------------------------------------- */
    int heathPotions;
    int manaPotions;
    int specPoints;
    /* -------------------------------------------------------------------------- */

    
    bool isAlive;
    /* -------------------------------------------------------------------------- */

    /**
     * This constructor creates a new Character based on the class given.
     *
     * @param name      Name of the character
     * @param className Class of the character (Warrior or Mage)
     */
    Character(std::string nombre = "Petetra", std::string nombreDeClase = "Warrior");
    //TODO Add Special moves using special items
    /* --------------------------------- Attack --------------------------------- */
    /**
     * This method prints out the character's attack statement and returns the value
     * of their attack.
     *
     * @return Attack Damage
     */

    //Paul: so would the cannon-staff move slower or need a partial turn to reload?
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

    std::string levelUp();

    void win();
    void gameover();

    //TODO Add Stat printout.

    //paul: oo this sounds nice
};

//#endif