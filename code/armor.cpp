
//#include "item.hpp" // Include the header file for the Item class
#include "armor.hpp"

/**
 * Ethan:
 *  ok fellas, here's how its gonna be:
 *  class members, functions, etc. are gonna be declared in the hpp.
 *  All definitions are going to be written in the corresponding cpp file
 *  in the following format:
 *      [ClassName]::[functionName/ConstructorName](//parameters//) {//implementation}
 * 
 *  The [ClassName]:: part is to say that you are defining something from the class,
 *  think std::
*/


// Constructor
Armor::Armor(std::string name, int value): Item(name, value) {}

// Special Constructor
Armor::Armor(std::string name, int value, std::string specialName, int specialValue)
    : Item(name, value, specialName, specialValue) {}

Armor::Armor(std::string name, int value, std::string specialName, int specialValue, std::string specialDescription)
    : Item(name, value, specialName, specialValue, specialDescription) {}

