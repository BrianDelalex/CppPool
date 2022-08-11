/*
** EPITECH PROJECT, 2019
** KoalaBot.hpp
** File description:
** 
*/

#ifndef KOALABOT_HPP_
#define KOALABOT_HPP_

#include "Parts.hpp"

class KoalaBot
{
public:
    KoalaBot(std::string name = "Bob-01");
    ~KoalaBot();
    void swapParts(Parts &part);
    void setParts(const Parts &part);
    void informations(void);
    bool status();
private:
    std::string _serial;
    Arms _arm;
    Legs _leg;
    Head _head;
};

#endif
