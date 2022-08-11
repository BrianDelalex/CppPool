/*
** EPITECH PROJECT, 2019
** IMonitorDisplay
** File description:
** Display interface
*/

#ifndef IMONITORDISPLAY_HPP_
#define IMONITORDISPLAY_HPP_

#include "SysInfo.hpp"
#include "CpuInfo.hpp"
#include "Display.hpp"
#include <iostream>

class Display;

class IMonitorDisplay
{
public:
    virtual ~IMonitorDisplay() = default;
    virtual void display() = 0;
    virtual void setController(Display *control) = 0;
};

#endif