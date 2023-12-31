#pragma once

#include <string>

class Item
{
public:
    std::string name;
    int value;
    std::string specialName;
    int specialValue;
    std::string specialDescription;
    
    Item();

    Item(std::string nam, int val);

    Item(std::string nam, int val, std::string specName, int specValue);

    Item(std::string nam, int val, std::string specName, int specValue, std::string specDescription);

    /* ---------------------------------- Name ---------------------------------- */
    std::string getName();
    void setName(std::string nam);
    /* ---------------------------------- Value --------------------------------- */
    int getValue();
    void setValue(int val);
    /* ------------------------------ Special Name ------------------------------ */
    std::string getSpecialName();
    void setSpecialName(std::string name);
    /* ------------------------------ Special Value ----------------------------- */
    int getSpecialValue();
    void setSpecialValue(int value);
    /* --------------------------- Special Description -------------------------- */
    std::string getSpecialDescription();
    void setSpecialDescription(std::string description);
};