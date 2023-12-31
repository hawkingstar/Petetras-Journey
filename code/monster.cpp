#include"monster.hpp"

//----------------------------------------------------------------------------//

    Monster::Monster(std::string name, int hp, int mp, int speed, Offense offense, 
    Defense defense, Armor armor)
        : name(name), hp(hp), maxHp(hp), mp(mp), maxMp(mp), speed(speed), offense(offense), defense(defense), armor(armor) {}
    
    


    /* --------------------------------- Attack --------------------------------- */
    /**
     * This method prints out the monster's attack statement and returns the value
     * of their attack.
     *
     * @return Attack Damage
     */
    int Monster::attack() {
        std::cout << name << " attacks with their " << offense.getName() << " for " << offense.getValue() <<" damage." << std::endl;
        block = 0;
        return offense.getValue();
    }

    /* --------------------------------- Defend --------------------------------- */
    /**
     * This method prints out the character's defend statement and sets their block
     * accordingly.
     */
    void Monster::defend() {
        std::cout << name << " defends with their " << defense.getName() << " and increases their damage mitigation for your next attack by " << defense.getValue() << " points."<< std::endl;
        block = defense.getValue();
        std::cout << std::endl;
    }

    /* ------------------------------- Take Damage ------------------------------ */
    /**
     * This method subtracts how much damage the character took (accounting for
     * armor) from their HP and then checks if they are dead.
     *
     * @param damage Damage to subtract
     */
    void Monster::takeDamage(int damage) { 
        int mitigation = armor.getValue() + block;
        int totalDamage = damage - mitigation;
        if (totalDamage < 0) {
            totalDamage = 0;
        }
        hp -= totalDamage;
        std::cout << name << " reduces your attack by " << mitigation <<" and takes " << totalDamage << " damage. " << name << " now has " << hp << " HP." << std::endl;
        std::cout << std::endl;
        checkAlive();
    }

    /* ---------------------------------- Heal ---------------------------------- */
    /**
     * This method adds the inputted value to the HP of the character, maxing out at
     * maxHp.
     *
     * @param healValue How much HP the character heals.
     */
    void Monster::heal(int healValue) {
        if (hp + healValue <= maxHp) {
            hp += healValue;
        } else {
            hp = maxHp;
        }
        std::cout << name << " heals " << healValue << " HP. " << name << " now has " << hp << " HP." << std::endl;
    }

    /* --------------------------------- Restore -------------------------------- */
    /**
     * This method adds the inputted value to the MP of the character, maxing out at
     * maxMP.
     *
     * @param manaValue How much MP the character recovers.
     */
    void Monster::restore(int manaValue) {
        if (mp + manaValue <= maxMp) {
            mp += manaValue;
        } else {
            mp = maxMp;
        }
    }

    /* ------------------------------- Check Dead ------------------------------- */
    /**
     * Checks if the character is dead.
     */
    bool Monster::checkAlive() {
        if (hp <= 0) {
            isAlive = false;
        }
        return isAlive;
    }

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
    Monster Monster::getMonster(std::string name) {
        // if (name == "Goblin") {
        //     return Monster("Goblin", 15, 0, 10, Offense("Rusty Sword", 3), Defense("Broken Shield", 3), Armor("Tattered Leather Armor", 1));
        // }
        // if (name == "Bandit") {
        //     return Monster("Drake", 8, 6, 16, Offense("Claws", 6), Defense("Draconic flesh", 10), Armor("Drake Scales", 0));
        // } 
        // if (name == "Bulette"){
        //     return Monster("Bulette", 20, 0, 3, Offense("Claws", 6), Defense("Armored Skin", 15), Armor("Flesh", 0));
        // }
        if (name == "S") {
            return Monster("Pore Spider", 12, 3, 4, Offense("Venomous Bite", 5), Defense("Toxic Carapace", 9), Armor("Exoskeleton", 7)); //ethan added armor
        }
        if (name == "C") {
            return Monster("Demonic Clone", 20, 0, 3, Offense("Demonic Grip", 10), Defense("Demonic Blood", 12), Armor("Demonic Sinew", 5)); //Ethan added armor
        }
        if (name == "B") {
            return Monster("Cursed Bat", 3, 2, 20, Offense("Piercing Gaze", 4), Defense("Bat Wings", 4), Armor("Cursed Fur", 1)); //Ethan added armor
        }
        if (name == "!") {
            return Monster("BOSS - Lord of Blood: Mohg", 20, 20, 20, Offense("Ritual Trident", 30), Defense("Robe of Blood", 20), Armor("Baleful Energy", 10));
        }

        throw std::invalid_argument("Invalid monster type.");
    }

    Monster Monster::getMonster(int floor) {
        if (floor <= 3) {
            return getMonster("Goblin");
        } else if (floor <= 5) {
            double random = static_cast<double>(rand()) / RAND_MAX;
            if (random <= 0.5) {
                return getMonster("Goblin");
            } else {
                return getMonster("Drake");
            }
        } else {
            return getMonster("Drake");
        }
    }

    /* ------------------------------ Random Action ----------------------------- */
    /**
     * This method randomly decides whether the monster attacks or defends and
     * returns the attack value if they are attacking.
     * If defending, the returned value is 0.
     *
     * @return damage done by monster
     */
    int Monster::randomAction() {
        double random = static_cast<double>(rand()) / RAND_MAX;
        if (random < 0.5) {
            return this->attack();
        } else {
            this->defend();
            return 0;
        }
    }

//Paul: get functions
std::string Monster::getname(){return name;}
    int Monster::gethp(){return hp;}
    int Monster::getmaxHp(){return maxHp;}
    int Monster::getmp(){return mp;}
    int Monster::getmaxMp(){return maxMp;}
    int Monster::getspeed(){return speed;}