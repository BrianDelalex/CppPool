/*
** EPITECH PROJECT, 2019
** SickKoala.cpp
** File description:
** 
*/

#include "SickKoala.hpp"
#include <iostream>

SickKoala::SickKoala(std::string str)
{
    _name = str;
}

SickKoala::~SickKoala() 
{
    std::cout << "Mr." << _name << ": Kreooogg!! I'm cuuuured!" << std::endl;
}

void SickKoala::poke()
{
    std::cout << "Mr." << _name << ": Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string str)
{
    if (str == "Mars") {
        std::cout << "Mr." << _name << ": Mars, and it kreogs!" << std::endl;
        return (true);
    } else if (str == "Buronzand") {
        std::cout << "Mr." << _name << ": And you'll sleep right away!" << std::endl;
        return (true);
    }
    std::cout << "Mr." << _name << ": Goerkreog!" << std::endl;
    return (false);
}

void SickKoala::overDrive(std::string str)
{
    std::string str2("Mr." + this->_name + ": ");
    int i = 0;
    int pos = 0;

    while ((pos = str.find("Kreog!", i)) != -1) {
        str2.append(str.substr(i, pos));
        str2.append("1337!");
        i = pos + 6;
    }
    str2.append(str.substr(i, str.length()));
    std::cout << str2 << std::endl;
}

std::string SickKoala::getName()
{
    return (this->_name);
}