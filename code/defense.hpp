#pragma once

#include "item.hpp" // Include the header file for the Item class

class Defense : public Item 
{
    
public:
    std::string name;
    int value;
    std::string specialName;
    int specialValue;
    std::string specialDescription;

    // Constructor
    Defense(std::string name, int value);

    // Special Constructor
    Defense(std::string name, int value, std::string specialName, int specialValue);

    Defense(std::string name, int value, std::string specialName, int specialValue, std::string specialDescription);

};