
//#include "item.hpp" // Include the header file for the Item class
#include "defense.hpp"


    // Constructor
    Defense::Defense(std::string name, int value) : Item(name, value) {}

    // Special Constructor
    Defense::Defense(std::string name, int value, std::string specialName, int specialValue)
        : Item(name, value, specialName, specialValue) {}

    Defense::Defense(std::string name, int value, std::string specialName, int specialValue, std::string specialDescription)
        : Item(name, value, specialName, specialValue, specialDescription) {}



