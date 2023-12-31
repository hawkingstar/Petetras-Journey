//#include "item.hpp" // Include the header file for the Item class |Ethan: dont need this since offense.hpp has it
#include "offense.hpp"


    // Constructor
    Offense::Offense(std::string name, int value): Item(name, value) {}

    // Special Constructor
    Offense::Offense(std::string name, int value, std::string specialName, int specialValue)
        : Item(name, value, specialName, specialValue) {}

    Offense::Offense(std::string name, int value, std::string specialName, int specialValue, std::string specialDescription)
        : Item(name, value, specialName, specialValue, specialDescription) {}

