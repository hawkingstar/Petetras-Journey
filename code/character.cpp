// #ifndef CHARACTER_H
// #define CHARACTER_H
#include"character.hpp"
#include<algorithm>

// #include<cctype>
// #include<string>
// // #include<stdio.h>
// #include<iostream>
// // #include<stdlib.h>
// #include<time.h>//Paul: some of these includes may not be necessary
// //------------------------------to Paul, from Ethan: I fixed the tolower compares and commented ouut errors
// //#include"offense.cpp"
// //#include"defense.cpp"
// //#include"armor.cpp"
// #include"general.hpp"
//#include"game.cpp" //Ethan: commented this out since game includes character.cpp
//Paul: more of these may be needed

//using namespace std;
    //Ethan: commented out namespace since professor mentioned it can cause problems 
    //in large projects


    /**
     * This constructor creates a new Character based on the class given.
     *
     * @param name      Name of the character
     * @param className Class of the character (Warrior or Mage)
     */
    Character::Character(std::string nombre, std::string nombreDeClase)
    {
        //General general = General();
        name = nombre;
        className = nombreDeClase;
        isAlive = true;
        attackValue = 10;
        hasKeyItem = false;
        hasBossKey = false;
        std::transform(className.begin(), className.end(), className.begin(),
        [](unsigned char c){ return std::tolower(c); });
        if (className == "warrior") //Paul: meaning of this bit?
                                             //Ethan: tolower only works on chars, used my
                                             //       own function
        { 
            hp = 20;
            maxHp = 20;
            mp = 10;
            maxMp = 10;
            speed = 10;
            //offense = new Offense("Basic Sword", 5); Ethan: not yet implemented------------------------------------
            //defense = new Defense("Basic Shield", 5);
            //armor = new Armor("Basic Armor", 2);
            specPoints = 0;
            heathPotions = 1;
            manaPotions = 0;

        } else if (className == "mage") { //Paul: hopefully tolower works
            hp = 10;
            maxHp = 10;
            mp = 20;
            maxMp = 20;
            speed = 8;
            //offense = new Offense("Basic Wand", 8); Ethan: not yet implemented-------------------------------------
            //defense = new Defense("Basic Scroll", 3);
            //armor = new Armor("Basic Robes", 1);
            specPoints = 0;
            heathPotions = 0;
            manaPotions = 1;

        }

    }
    //TODO Add Special moves using special items
    /* --------------------------------- Attack --------------------------------- */
    /**
     * This method prints out the character's attack statement and returns the value
     * of their attack.
     *
     * @return Attack Damage
     */

    //Paul: so would the cannon-staff move slower or need a partial turn to reload?
    int Character::attack() 
    {
        //std::cout << name + " attacks with their " + offense.getName() + "." << std::endl; Ethan: not yet implemented-------------------------------------
        block = 0;
        int weaponDamage = hasKeyItem ? 30 : 0;
        std::cout << "---------------------------------" << std::endl;
        std::cout << name + " attacks for " << attackValue + weaponDamage << " damage." << std::endl;
        std::cout << "---------------------------------\n" << std::endl;

        return attackValue + weaponDamage; //offense.getValue(); Ethan: not yet implemented---------------Cory: Adding a placeholder for player attack value----------------------
    }

    /* --------------------------------- Defend --------------------------------- */
    /**
     * This method prints out the character's defend statement and sets their block
     * accordingly.
     */
    void Character::defend() 
    {
        //std::cout << name + " defends with their " + defense.getName() + "." << std::endl; Ethan: not yet implemented-------------------------------------
        //block = defense.getValue();
        block = 10;
        std::cout << "Petetra increases his defenses, mitigating the next attack's damage by an additional 10 for 1 turn " <<std::endl;
    }


    /* ------------------------------- Take Damage ------------------------------ */
    /**
     * This method subtracts how much damage the character took (accounting for
     * armor) from their HP and then checks if they are dead.
     *
     * @param damage Damage to subtract
     */
    void Character::takeDamage(int damage) 
    {
        int mitigation = 10 + block + hasKeyItem ? 20 : 0;
        int totalDamage = damage - /*armor.getValue()*/mitigation; //Ethan: not yet implemented, 10 is placeholder-------------------------------------
        if (totalDamage < 0) {
            totalDamage = 0;
        }
        hp -= totalDamage;
        std::cout << name + " reduces the damage taken by "<< mitigation << " and takes " + std::to_string(totalDamage) + " damage. " + name + " now has " + std::to_string(hp) 
        + "HP." << std::endl;
        std::cout << " " << std::endl;
        if(!checkAlive())
            gameover();
    }
    /* ---------------------------------- Heal ---------------------------------- */
    /**
     * This method adds the inputted value to the HP of the character, maxing out at
     * maxHp.
     *
     * @param healValue How much HP the character heals.
     */
    void Character::heal(int healValue) 
    {
        if (hp + healValue <= maxHp) 
        {
            hp += healValue;
        } else 
        {
            hp = maxHp;
        }
        hp = std::min(hp+healValue, maxHp);//Paul: simplified from previous code
        std::cout << name + " heals " + std::to_string(healValue) + " HP. " + name + " now has " + std::to_string(hp) + "HP." << std::endl;
    }

    /* --------------------------------- Restore -------------------------------- */
    /**
     * This method adds the inputted value to the MP of the character, maxing out at
     * maxMP.
     *
     * @param manaValue How much MP the character recovers.
     */
    void Character::restore(int manaValue) 
    {
        mp = std::min(mp+manaValue, maxMp);//Paul: simplified from previous code
    }

    /* ------------------------------- Check Dead ------------------------------- */
    /**
     * Checks if the character is dead.
     */
    bool Character::checkAlive() {
        if (hp <= 0) {
            isAlive = false;//Paul: huh?
            //Game.gameover(); Ethan: Game cannot be a class.
                                    //if we want, we can move gameover()
                                    // here.
            
        }
        return isAlive;
    }

    /*----Level Up----*/
    std::string Character::levelUp() {
        
        maxHp += 5;
        hp = maxHp;
        attackValue +=5;

        return "You leveled up! Petetra's attack and max hp have increased by 5 points!";
    }

    std::string Character::getname() {return name;}
    int Character::gethp(){return hp;}
    int Character::getmaxHp(){return maxHp;}
    int Character::getmp(){return mp;}
    int Character::getmaxMp(){return maxMp;}
    int Character::getspeed(){return speed;}

    void Character::gameover() {
        std::cout << "You died!\nGAMEOVER!" << std::endl;
        exit(0);
    }

    void Character::win()
    {
        std::cout << "---------YOU WIN!!!!!----------" << std::endl;
        std::cout << "See you next time!" << std::endl;
        exit(0);
    }


    //TODO Add Stat printout.

    //paul: oo this sounds nice


//#endif