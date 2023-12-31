#include"combat.hpp"
//#include<string>
//#include<iostream> //does this have good reading functionality?
//#include<random> //Paul: does this have the same usefullness of java's random?
//Paul: these three were included again even though they already were in the header


// #include<stdlib.h>

// #include<cstdlib> //or this? The way it works is kinda weird
// #include<cstring>

//using namespace std;
    Combat::Combat(Character jugador, Monster enemigo) 
    {
        player = jugador;
        enemy = enemigo;
        turnCount = 1;
    }
    /**
     * Put this into Dungeon class
     */

    //Paul: should we?
    void Combat::startFight() 
    {
        std::cout << player.getname() + " has encountered " + enemy.getname() + "!" << std::endl;

        while(player.checkAlive() && enemy.checkAlive()) { 
            //Paul: may need to create functions to access private variables?
            //Paul: Checkdead is true if the thing is alive
            int enemyAction = 0;
            //Scanner in = new Scanner(System.in); //paul: what to do with a scanning?
            std::cout << "----- START TURN " << turnCount << "-----" << std::endl;

            std::cout << "What would you like to do? (A)ttack or (D)efend?" << std::endl;
            std::cin >> choice;
            //for (int x=0; x<strlen(choice); x++) putchar(tolower(choice[x]));
            //choice = boost::trim(choice);
            //choice = choice.toLowerCase().trim();

            //choice = toLowerCase(choice);
            std::transform(choice.begin(), choice.end(), choice.begin(),
            [](unsigned char c){ return std::tolower(c); });//lowercasing

            //choice = choice.trim();
            //actually no need for trim
            std::cout << "\n" << std::endl;

            if(std::tolower(choice[0]) == 'a' || std::tolower(choice[0]) == 'd')
            {
                if (player.getspeed() >= enemy.getspeed()) {
                    if (choice[0] == 'a') {
                        enemy.takeDamage(player.attack());
                        if (enemy.checkAlive()) {
                            enemyAction = enemy.randomAction();
                            if (enemyAction > 0) {
                                player.takeDamage(enemyAction);
                            }
                        } else {
                            break;
                        }
                    }else if (choice[0] == 'd') {
                        player.defend();
                        enemyAction = enemy.randomAction();
                        if (enemyAction > 0) {
                            player.takeDamage(enemyAction);
                        }
                    }
                }else {
                    enemyAction = enemy.randomAction();
                    if (enemyAction > 0) {
                        player.takeDamage(enemyAction);
                    }
                    if (choice[0] == 'a') {
                        enemy.takeDamage(player.attack());
                    }else if (choice[0] == 'd') {
                        player.defend();
                    }
                }
            } else
            { //handling a wrong in put
                std::cout<< "Oops, you didn't insert a valid input :( .  Try again." << std::endl;
                continue;
            }
            //Paul: we should create a response for incorrect inputs. Ok now I think I did it. 
            turnCount++;
            std::cout << "|\n|\n|\n|\n|\n|" << std::endl;
        }
        /*if(!player.checkAlive())
            player.gameover(); */
        std::cout << "You killed the " + enemy.getname() + "!\n\n\n" << std::endl;
        
        std::cout << player.levelUp() << std::endl;
    }
