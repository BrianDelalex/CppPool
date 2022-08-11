/*
** EPITECH PROJECT, 2019
** Skat.hpp
** File description:
** 
*/

#ifndef SKAT_HPP_
#define SKAT_HPP_

#include <iostream>

class Skat
{
public:
    Skat(const std::string &name, int stimPaks);
    Skat();
    ~Skat();
    int &stimPaks();
    const std::string &name();
    void shareStimPaks(int number, int &stock);
    void addStimPaks(unsigned int number);
    void useStimPaks();
private:
    void status();
    int _stimPaks;
    std::string _name;
};

#endif
