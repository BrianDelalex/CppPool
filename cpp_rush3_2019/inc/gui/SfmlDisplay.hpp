/*
** EPITECH PROJECT, 2019
** SfmlDisplay.hpp
** File description:
** 
*/

#ifndef SFMLDISPLAY_HPP_
#define SFMLDISPLAY_HPP_

#include "IMonitorDisplay.hpp"
#include "environnement.hpp"
#include "CpuInfo.hpp"
#include "SysInfo.hpp"
#include "MemInfo.hpp"
#include "Display.hpp"
#include <list>
#include <SFML/System/Time.hpp>
#include <algorithm>
#include <iomanip>

class SfmlDisplay : public IMonitorDisplay
{
public:
    SfmlDisplay();
    ~SfmlDisplay();
    void display();
    void handleEvent();
    int handleInput(sf::Event::KeyEvent key);
    void displaySysInfo();
    void displayMemInfo();
    void displayCpuInfo();
    void displayCpuTemp();
    void displayNetInfo();
    void displayProcessInfo();
    void setController(Display *control);
private:
    sf::RenderWindow *wd;
    sf::Event evt;
    sf::Vector2f linePos;
    std::list<sf::RectangleShape> memRects;
    std::list<sf::RectangleShape> tempRects;
    SysInfo *sysInfo;
    CpuInfo *cpuInfo;
    MemInfo *memInfo;
    Display *controller;
};

#endif
