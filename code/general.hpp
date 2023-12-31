#pragma once
#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>

//this file exists to have common-need functions available to all files via an #include
// -Ethan Purser

/**
 * @author Ethan Purser
 * @param str is string you want to convert
 * @return is the lower case std::string version of argument str
 * 
 * ps: i made this since i couldnt find one online
*/

std::string toLowerCase(std::string str);
std::string toLowerCase(std::string str)
{
    //if character cannot be lowercased, tolower() leaves it unchanged.
    // for(char c : str)
    // {
    //     c = tolower(c);
    
    // return str;
    
    std::string data = str;
    std::transform(data.begin(), data.end(), data.begin(),
    [](unsigned char c){ return std::tolower(c); });
    return data;
}