#pragma once

//#include<string.h>
#include<string>
//#include<stdio.h>
#include<iostream> //does this have good reading functionality?
                   //Ethan: you can pipe pretty much anything into anything with it,
                   //       including files  
//#include<stdlib.h>
#include<random> //does this have the same usefullness of java's random?
//#include<cstdlib> //or this
//#include<stdlib.h>
#include<vector>
#include<list>
//#include<concepts>

#include<algorithm>

//using namespace std;
    //Ethan: commented out since it can cause issues long term

#include"character.hpp"
//these following two were included to create encounters
#include"combat.hpp"
#include"monster.hpp"

#include"cave.hpp"
#include"item.hpp"

//#include"general.hpp"
#include"dialogue.hpp"
#include<algorithm>
//#include"general.cpp" should be included from character


class Dungeon
{
private:
    std::vector<std::vector<std::string>> emptymap;
    std::vector<std::vector<std::string>> firstMap = 
        {
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
        {"#", "X", "X", "X", "B", "X", "X", "X", "X", "#"},
        {"#", "X", "#", "#", "#", "X", "#", "#", "X", "#"},
        {"#", "X", "#", "T", "#", "X", "#", "#", "X", "#"},
        {"#", "X", "#", "X", "#", "X", "#", "#", "X", "#"},
        {"#", "X", "#", "X", "#", "X", "#", "#", "S", "#"},
        {"#", "X", "#", "X", "#", "X", "#", "#", "T", "#"},
        {"#", "X", "#", "X", "#", "X", "#", "#", "#", "#"},
        {"#", "X", "#", "X", "#", "X", "C", "X", "X", "#"},
        {"#", "X", "#", "C", "#", "#", "#", "#", "X", "#"},
        {"#", "X", "X", "X", "#", "#", "#", "#", "!", "#"},
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#"}
        };
        std::vector<std::vector<std::string>> eastMap = 
        {
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
        {"#", "X", "X", "X", "X", "X", "X", "X", "X", "#"},
        {"#", "X", "X", "X", "X", "X", "X", "X", "X", "#"},
        {"#", "X", "X", "X", "X", "X", "X", "X", "X", "#"},
        {"#", "X", "X", "X", "X", "X", "X", "X", "X", "#"},
        {"D", "X", "X", "X", "X", "X", "X", "X", "X", "#"},
        {"#", "X", "X", "X", "X", "X", "X", "X", "X", "#"},
        {"#", "X", "X", "X", "X", "X", "X", "X", "X", "#"},
        {"#", "X", "X", "X", "X", "X", "X", "X", "X", "#"},
        {"#", "X", "X", "X", "X", "X", "X", "X", "X", "#"},
        {"#", "X", "X", "X", "X", "X", "X", "X", "X", "#"},
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#"}
        };

    bool win = false;
    Character player;//Paul: storing relevant data about petetra
    std::list<Cave> allCaves;//Paul: all the caves, simple as
    std::list<Cave> allCavesExplored;//Paul: to map what has changed
    int playerX;//Paul: coordinates of the player
    int playerY;
    Cave currentCave;
    std::vector<std::string>currentOptions;//Paul: for things like accessing the shop
    std::vector<Item> inventory;//Paul: storing petetra's inventory
    std::vector<Item> currentShopCatalogue;

    void moveSuccess(Cave& currentCave);

    void firstCave();

    void actPrompt();

    /**
     * will be used to relocate player
    */
    void move(std::string choice, Cave& currentCave);

    /**
     * will be used to print map on command
    */
    void printMap(Cave currentCave);

    /**
     * used to trigger combat using combat class
    */
    void roomCombat();


public:
    Dungeon (Character jugador);

    void dungeonStart();
};
// class Dungeon 
// {
// private:
//     //std::random random = Random();
//     //std::srand(std::time(nullptr));
//     //Paul: no this does not need to be initialized like java
//     bool win = false;

// public:
//     Character player;
//     int mapLength;
//     std::string[][] map; //initializing a c++ array?
//     std::int treasuresLeft = 2;
    
    
    

//     Dungeon (Character player, int mapLength) 
//     {
//         //Scanner in = new Scanner(System.in);
//         this.player = player;
//         this.mapLength = mapLength;
//         this.map = std::string[2][mapLength];
//         fillSpace();
//         for (int i = treasuresLeft; i > 0; i--) {
//             treasureGen(1, (mapLength / 2) - 2);
//         }
//         for (int i = treasuresLeft; i > 0; i--) {
//             treasureGen(mapLength / 2, (mapLength) - 2);
//         }
//         fireGen(1, (mapLength / 2) - 2);
//         fireGen(mapLength / 2, (mapLength) - 2);
//         //by this point, everything generated
//         printMap(map);
//         //test runs
//         while(!win) {
//             for (int i = 0; i < map[1].length; i++) {
//                 if (map[1][i].equals("(^)")) {
//                     if (map[0][i].equals("[ ]")) {
//                         roomCombat();
//                     }
//                 }
                
//             }
//             for (int i = 0; i < map[1].length; i++) {

//             }
//             playerMove();
//             printMap(map);
//             std::cout << "\n" << std::endl;
//         }
//     }
    
// /* -------------------------------------------------------------------------- */
//     void gameLoop() 
//     {
//     //read
//     //act
//     //move
//     //print
//     //cut paste into constructor
    
//     }
// /* -------------------------------------------------------------------------- */
//     void playerMove() 
//     {
//     for (int i = 0; i < map[1].length; i++) 
//     {
//         if (map[1][i].equals("(^)")) 
//         {
//             map[1][i] = "   ";
//             map[1][i + 1] = "(^)";
            
//         }
//     }
//     }
// /* -------------------------------------------------------------------------- */
//     void roomCombat()
//     {
//         Combat fight = Combat(player, Monster.getMonster("goblin"));
//         fight.startFight();
//     }
// /* -------------------------------------------------------------------------- */
//     /**
//      * Desc: Fills map with "[ ]", "[S]", and "[B]" as well as player position..
//      */
//     void fillSpace() 
//     {
//         for (int i = 0; i < map[0].length; i++) 
//         {
//             if (i == (mapLength / 2) - 1)
//             {
//                 map[0][i] = "[S]";
//             } else if (i == (mapLength) - 1) 
//             {
//                 map[0][i] = "[B]";
//             }  else 
//             {
//                 map[0][i] = "[ ]";
//             }

//         }
//         for (int i = 0; i < map[1].length; i++) 
//         {
//             map[1][0] = "(^)";
//             if (i != 0) 
//             {
//                 map[1][i] = "   ";
//             }
//         }
//     }
// /* -------------------------------------------------------------------------- */
//     /**
//      * Desc: generates a random number between 2 given bounds and sents treasure at that index, with no duplicates
//      * @param firstBound first given bound
//      * @param secondBound second given bound
//      */

//     /*
//     Here's a c++ implementation:
//     int range = max - min + 1;
//     int num = rand() % range + min;
//     */
//     void treasureGen(int firstBound, int secondBound) 
//     {
//         int randomIndex = random.nextInt((secondBound - firstBound) + 1) + firstBound;
//         bool done = false;
//         while(!done) 
//         {
//             if (!(map[0][randomIndex - 1].equals("[T]")) && !(map[0][randomIndex + 1].equals("[T]")) && !(map[0][randomIndex].equals("[T]"))) {
//                 map[0][randomIndex] = "[T]";
//                 done = true;
//             } else {
//                 randomIndex = random.nextInt((secondBound - firstBound) + 1) + firstBound;
//             }
//         }


//     }
// /* -------------------------------------------------------------------------- */
//     /**
//      * Desc: generates fire at a random position within given bounds
//      * @param firstBound first bound
//      * @param secondBound second bound
//      */
//     void fireGen(int firstBound, int secondBound) {
//         int randomIndex = random.nextInt((secondBound - firstBound) + 1) + firstBound;
//         bool done = false;
//         while(!done) {
//             //dont let it override treasure, no need for dupe protection
//             if (!(map[0][randomIndex].equals("[T]"))) 
//             {
//                 map[0][randomIndex] = "[F]";
//                 done = true;
//             } else 
//             {
//                 randomIndex = random.nextInt((secondBound - firstBound) + 1) + firstBound;
//             }
//         }
//     }
// /* -------------------------------------------------------------------------- */
//     /**
//      * Prints the contents of the double array
//      * @param arr input double array
//      */
//     void printMap(string[][] arr) 
//     {
//         for (int i = 0; i < arr[0].length; i++) 
//         {
//             std::cout << arr[0][i] << std::endl; //should this be nested instead?
//         }
//         std::cout << "\n" << std::endl;
//         for (int i = 0; i < arr[1].length; i++) 
//         {
//             std::cout << arr[1][i] << std::endl;
//         }
//     }
// };