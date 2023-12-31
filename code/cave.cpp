#include"cave.hpp"
// #include<string.h>
#include<string>
#include<vector>
// #include<stdio.h>
#include<iostream> //does this have good reading functionality?
// #include<stdlib.h>
//#include<random> //does this have the same usefullness of java's random?
// #include<cstdlib> //or this
//#include<vector>



//#include"character.cpp"
//#include"combat.cpp"
//#include"monster.cpp"


Cave::Cave() //default constructor, meant to resolve strange issues, revisit if some strange construction errors
       //-Ethan
{

}
    
Cave::Cave(std::string name, Cave *n, Cave *s, Cave *e, Cave *w, std::vector<std::vector<std::string>> newmap)
{
    north = n;
    south = s;
    east = e;
    west = w;

    localmap = newmap;
    visited = false;
}

//Ethan: moved functions in public space, kinda useless otherwise
void Cave::enterCave()
{
    visited = true;
    std::cout << "Entering cave: " + name << std::endl;
}

void Cave::printName()
{
    std::cout << "You are in " + name << std::endl;
}

void Cave::setCardinal(Cave* cardinal, Cave target)//Paul: pointers, man. They're hard
{
    cardinal = &target;
}

Cave* Cave::getNorth()
{
    return north;
}

Cave* Cave::getSouth()
{
    return south;
}

Cave* Cave::getEast()
{
    return east;
}

Cave* Cave::getWest()
{
    return west;
}

std::vector<std::vector<std::string>> Cave::getmap()
{
    return localmap;
}
