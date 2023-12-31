//file made by Ethan
#pragma once

#include "item.hpp" // Include the header file for the Item class
    //make item.hpp
class Armor : public Item
{

public:
    std::string name;
    int value;
    std::string specialName;
    int specialValue;
    std::string specialDescription;

    // Constructor
    Armor(std::string name, int value);

    // Special Constructor
    Armor(std::string name, int value, std::string specialName, int specialValue);

    Armor(std::string name, int value, std::string specialName, int specialValue, std::string specialDescription);

};