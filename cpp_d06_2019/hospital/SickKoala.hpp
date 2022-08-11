/*
** EPITECH PROJECT, 2019
** SickKoala.hpp
** File description:
** 
*/

#ifndef SICK_KOALA_HPP_
#define SICK_KOALA_HPP_

#include "iostream"

class SickKoala
{
public:
    SickKoala(std::string str);
    ~SickKoala();
    void poke(void);
    bool takeDrug(std::string str);
    void overDrive(std::string str);
    std::string getName(void);
private:
    std::string _name;
};

#endif