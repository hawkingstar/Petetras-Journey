#pragma once
// // #include<string.h>
#include<string>
#include<vector>



//#include"character.cpp"
//#include"combat.cpp"
//#include"monster.cpp"

class Cave //Ethan: made Cave uppercase so its obvious as an object type
{   
private:
    std::string name;
    Cave *north, *south, *east, *west;
    bool visited;
    std::vector<std::vector<std::string>> localmap;
    //paul: local map is to be changed, but the default appearance is to be stored in the dungeon class
    

public:
    Cave(); //default constructor, meant to resolve strange issues, revisit if some strange construction errors
           //-Ethan
    
    Cave(std::string name, Cave *n, Cave *s, Cave *e, Cave *w, std::vector<std::vector<std::string>> newmap);

    //Ethan: moved functions in public space, kinda useless otherwise
    void enterCave();

    void printName();
    
    void setCardinal(Cave* cardinal, Cave target);

    Cave* getNorth();
    Cave* getSouth();
    Cave* getEast();
    Cave* getWest();
    
    std::vector<std::vector<std::string>> getmap();
    
};