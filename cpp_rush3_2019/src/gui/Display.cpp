/*
** EPITECH PROJECT, 2019
** Display.cpp
** File description:
** 
*/

#include "Display.hpp"

Display::Display(IMonitorDisplay *mode1, IMonitorDisplay *mode2, void (IMonitorDisplay::*func)(void))
{
    this->mode1 = mode1;
    this->mode2 = mode2;
    mode1->setController(this);
    mode2->setController(this);
    this->mode = true;
    this->dispFunc = func;
}

Display::~Display() {}

void Display::display()
{
    if (mode) 
    {
        (this->mode1->*(this->dispFunc))();
        if (mode == false)
            display();
    }
    else
    {
        (this->mode2->*(this->dispFunc))();
        if (mode == true)
            display();
    }
}

void Display::changeMode()
{
    this->mode = !(this->mode);
}