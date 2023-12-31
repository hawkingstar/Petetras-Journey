#pragma once
#include "item.hpp" // Include the header file for the Item class

class Offense : public Item
{

public:
    std::string name;
    int value;
    std::string specialName;
    int specialValue;
    std::string specialDescription;

    // Constructor
    Offense(std::string name, int value);

    // Special Constructor
    Offense(std::string name, int value, std::string specialName, int specialValue);

    Offense(std::string name, int value, std::string specialName, int specialValue, std::string specialDescription);

};