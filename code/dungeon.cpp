#include "dungeon.hpp"

void Dungeon::firstCave() // Ethan: adding more caves
{

    Cave north1 = Cave("north1", &north1, &north1, &north1, &north1, emptymap);
    Cave west1 = Cave("west1", &west1, &west1, &west1, &west1, emptymap);
    Cave east1 = Cave("east1", &east1, &east1, &east1, &east1, emptymap);
    Cave south1 = Cave("south1", &south1, &south1, &south1, &south1, emptymap);

    Cave firstCave = Cave("first cave", &north1, &west1, &east1, &south1, firstMap);
    north1.setCardinal(north1.getSouth(), firstCave);
    south1.setCardinal(south1.getNorth(), firstCave);
    east1.setCardinal(east1.getWest(), firstCave);
    west1.setCardinal(west1.getEast(), firstCave);
    playerX = 1;
    playerY = 1;
    currentCave = firstCave;
    allCaves.push_back(firstCave);
    // when petetra leaves this cave currentCave will go into allcavesexplored so that
    // data about where he has walked does not affect the internal data of the game.
    // If petetra dies and respawns we can use this 'explored' data, you see?
    // Notice how currentCave copies firstCave by value, not by address.
}

void Dungeon::actPrompt()
{
    std::string choice;
    std::cout << "Where would you like to move? Any actions?"
              << "\n N) North \n S) South\n E) East\n W) West \n Be aware, "
              << "I will only read your first letter" << std::endl;
    // Ethan: prints with escape characters need to be all on the same line lest issues arise
    // Paul: here we will print other options
    std::cin >> choice;
    move(choice, currentCave);
    
    // Paul: here we will have if statements depending on what the character inputs.
    // These will have to change over time as new possible options become available
    // to the player such as accessing a shop or going to another room.

    // When the player makes a decision to move, the program will decide if any
    // direction is invalid because the relevant tile is occupied by a 'wall'
    // or a "#". If it is valid, the position of the "@" player will be moved
    // on the local map, and the variables playerX and playerY will be adjusted.

    // If petetra just walked into an encounter the combat function here will check
    // if there is an enemy dude here. If so, the combat will start. When it ends
    // it'll give the player the relevant information and the flow of code will return
    // right back to here. Then the actprompt will be run again with a while loop
    // until something else happens.

    // I'm thinking that there is no need to show the final boss in the final
    // room, the combat just starts when you enter.

    // Hopefully this works. these are my ideas for tiles:
    //@ is petetra
    // # is a wall
    // X is areas out of sight
    // O is areas in sight or already seen. We could also use "."
    // since it looks more like gravel on a cave floor.
    //$ is the shop
    // ß (alt-225) is fire. We could also use F.
    //! is treasure.
    //~ is unaccessible terrain, like water or lava
    //% could also be unaccessible terrain, but more solid.
    //& could be the 'sage' petetra meets.
}

void Dungeon::moveSuccess(Cave& currentCave) //Ethan: passing by reference, remove this if it breaks
{
    currentCave.getmap()[playerY][playerX] = "O";
    if(currentCave.getmap()[playerY][playerX] == "!") {
        if (player.hasBossKey == false || player.hasKeyItem == false) {
            std::cout<<"\n---------------------------------------------------"<<std::endl;
            std::cout << "You need both the boss key and cannon-staff before you can challenge the boss!" << std::endl;
        } else {
            std::string monster = currentCave.getmap()[playerY][playerX];
            Combat fight = Combat(player, Monster::getMonster(monster));
            std::cout<<theSage;
            std::cout<<meetingObwer;
            fight.startFight();
                //here after the fight, the below code should only be accessed in a winning condition
            player.win();


        }
    } else if ((currentCave.getmap()[playerY][playerX] == "C") ||
        (currentCave.getmap()[playerY][playerX] == "B") ||
        (currentCave.getmap()[playerY][playerX] == "S"))
    {
        currentCave.getmap()[playerY][playerX] == "X"; //should remove the monster, but it does not
        std::cout << "Combat Initiated!" << std::endl;
        std::string monster = currentCave.getmap()[playerY][playerX];
        Combat fight = Combat(player, Monster::getMonster(monster));
        fight.startFight();
        // printMap();
    }
    std::cout<<"\n---------------------------------------------------"<<std::endl;
}

/**
 * will be used to relocate player
 */
void Dungeon::move(std::string choice, Cave& currentCave) //cave passes by reference
{
    std::string situation = choice;
    std::transform(choice.begin(), choice.end(), choice.begin(),
                   [](unsigned char c)
                   { return std::tolower(c); });
    char letter = situation[0];
    switch (std::tolower(letter))
    {
    case 'n':
        if (currentCave.getmap()[playerY - 1][playerX] == "#")
        {
            std::cout<<"\n---------------------------------------------------"<<std::endl;
            std::cout << "Bumped into a wall. Idiot." << std::endl;
        } else if(currentCave.getmap()[playerY - 1][playerX] == "T") {
            if (!player.hasKeyItem) {
                player.hasKeyItem = true;
                std::cout << "You got: Cannon-staff!" << std::endl;
                std::cout << "This will help greatly with defeating your enemies" << std::endl;
            }
            playerY--;
            moveSuccess(currentCave);

        }
        // move north
        else if (currentCave.getmap()[playerY - 1][playerX] != "#")
        // for collision, we can add other impassable things later
        { // paul: adding this to see if it works
            playerY--;
            moveSuccess(currentCave);
        }

        break;
    case 's':
        // move south
        if (currentCave.getmap()[playerY + 1][playerX] == "#"){
            std::cout<<"\n---------------------------------------------------"<<std::endl;
            std::cout << "Bumped into a wall. Idiot." << std::endl;
        } else if(currentCave.getmap()[playerY + 1][playerX] == "T") {
            if (!player.hasBossKey) {
                player.hasBossKey = true;
                std::cout << "You got: Boss Key!" << std::endl;
            }
            playerY++;
            moveSuccess(currentCave);
        } 
        else if (currentCave.getmap()[playerY + 1][playerX] != "#")
        {
            playerY++;
            moveSuccess(currentCave);
        }

        break;
    case 'e':
        // move east
        if (currentCave.getmap()[playerY][playerX + 1] != "#")
        {
            playerX++;
            moveSuccess(currentCave);
        }
        else if (currentCave.getmap()[playerY][playerX + 1] == "#")
        {std::cout<<"\n---------------------------------------------------"<<std::endl;
            std::cout << "Bumped into a wall. Idiot." << std::endl;
        }
        break;
    case 'w':
        // move west
        if (currentCave.getmap()[playerY][playerX - 1] != "#")
        {
            playerX--;
            moveSuccess(currentCave);
        }
        else if (currentCave.getmap()[playerY][playerX - 1] == "#")
        {std::cout<<"\n---------------------------------------------------"<<std::endl;
            std::cout << "Bumped into a wall. Idiot." << std::endl;
        }
        break;
    default:
        std::cout<<"\n---------------------------------------------------"<<std::endl;
        std::cout << "Not a movement." << std::endl; // Paul: just a placeholder until we come up with other interactives
        // Paul: make sure to give the player another chance
        // if things are time sensitive.
    }
    // Paul: and after the move is done, we print the map Ethan: I wonder if we should only print on demand as opposed to every move
    //std::cout<<"\n---------------------------------------------------"<<std::endl;
    printMap(currentCave);
}

/**
 * will be used to print map on command
 */
void Dungeon::printMap(Cave currentCave)
{
    // iterate through current map matrix and print the tiles in
    // the proper shape
    int rowNumber = 0;
    int columnNumber = 0;
    for (std::vector<std::string> &row : currentCave.getmap()) // paul 10/22: should we capitalize the M in localmap? Ethan: yeah i use camel-case when coding
    {
        for (std::string &column : row)
        {
            if (rowNumber == playerY && columnNumber == playerX)
            {
                std::cout << "@"
                          << " ";
            }
            else if ((column == "C") || (column == "S") || (column == "B"))
            {
                std::cout << "X"
                          << " ";
            }
            else
            {
                std::cout << column << " ";
            } // paul: maybe ignore this code right now
            columnNumber++;
        }
        columnNumber = 0;
        std::cout << std::endl;
        rowNumber++;
    }
    // if a tile is discovered, then its printed. if you discovered a monster tile, do not print that its a monster, print as empty room
    //  int rowNumber=0; int columnNumber = 0;
    //  for(const auto &row : currentCave.getmap()) //matrix iteration using pass by reference
    //  {
    //      for(const auto &column : row)
    //      {
    //          //for every tile, print it out
    //          //X for undiscovered,
    //          //Other letters to be determined later based on object inside that tile
    //          //also needs to print in-shape
    //          if(rowNumber == playerY&&columnNumber==playerX){
    //              std::cout<<"@";
    //          } else {
    //              std::cout<<column;
    //          }//paul: maybe ignore this code right now 10/30/2023
    //          columnNumber++;
    //      }
    //      std::cout<< " " <<std::endl;
    //      rowNumber++;
    //  }
}

/**
 * used to trigger combat using combat class
 */
void Dungeon::roomCombat()
{
}

Dungeon::Dungeon(Character jugador)
{
    player = jugador; // paul: how does this work?
    // Ethan: moved the functions out of the constructor because im apprehensive
    //        about doing core logic in constructor for readability purposes
    // paul: gotcha
}

void Dungeon::dungeonStart()
{
    firstCave();
    // sets up the initial map state
    std::cout << openingBlurb << std::endl; // paul: first bit of dialogue
    printMap(currentCave);
    while (true)                            // Paul: for now
    {
        actPrompt();
        // initiates user interactivity
    }
}

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
