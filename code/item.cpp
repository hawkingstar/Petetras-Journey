#include "item.hpp"

        //broke something, commented -Ethan
    //Item::Item();

    Item::Item(std::string nam, int val)
    {
        name = nam;
        value = val;
        specialName = "";
        specialValue = 0;
        specialDescription = "";
    }

    Item::Item(std::string nam, int val, std::string specName, int specValue)
    {
        name = nam;
        value = val;
        specialName = specName;
        specialValue = specValue;
        specialDescription = "";
    }

    Item::Item(std::string nam, int val, std::string specName, int specValue, std::string specDescription)
    {
        name = nam;
        value = val;
        specialName = specName;
        specialValue = specValue;
        specialDescription = specDescription;
    }

    /* ---------------------------------- Name ---------------------------------- */
    std::string Item::getName() {return name;}
    void Item::setName(std::string nam) {name = nam;}
    /* ---------------------------------- Value --------------------------------- */
    int Item::getValue() {return value;}
    void Item::setValue(int val) {value = val;}
    /* ------------------------------ Special Name ------------------------------ */
    std::string Item::getSpecialName() {return specialName;}
    void Item::setSpecialName(std::string name) {specialName = name;}
    /* ------------------------------ Special Value ----------------------------- */
    int Item::getSpecialValue() {return specialValue;}
    void Item::setSpecialValue(int value) {specialValue = value;}
    /* --------------------------- Special Description -------------------------- */
    std::string Item::getSpecialDescription() {return specialDescription;}
    void Item::setSpecialDescription(std::string description) {specialDescription = description;}

