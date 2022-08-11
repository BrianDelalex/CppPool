/*
** EPITECH PROJECT, 2019
** Display.hpp
** File description:
** 
*/

#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include "../sync/IMonitorDisplay.hpp"

class IMonitorDisplay;

class Display
{
public:
    Display(IMonitorDisplay *mode1, IMonitorDisplay *mode2, void (IMonitorDisplay::*func)(void));
    ~Display();
    void display();
    void changeMode();
private:
    void (IMonitorDisplay::*dispFunc)(void);
    IMonitorDisplay *mode1;
    IMonitorDisplay *mode2;
    bool mode;
};

#endif
