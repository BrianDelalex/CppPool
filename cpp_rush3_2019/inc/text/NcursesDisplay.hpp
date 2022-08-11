/*
** EPITECH PROJECT, 2019
** text.hpp
** File description!
** Ncurses hpp
*/

#pragma once

#include <ncurses.h>
#include "../sync/IMonitorDisplay.hpp"
#include "../modules/CpuInfo.hpp"
#include "../modules/SysInfo.hpp"
#include "../modules/MemInfo.hpp"
#include <sys/ioctl.h> //ioctl() and TIOCGWINSZ
#include <unistd.h>
#include <cstring>
#include "../gui/Display.hpp"
#include "../modules/NetInfo.hpp"

class NcursesDisplay : public IMonitorDisplay
{
    public:
        NcursesDisplay();
        ~NcursesDisplay();
        void initWindowsStatic();
        void display();
        void fetchRam();
        void fetchTemp();
        void fetchNetwork();
        void setController(Display *control);
    private:
        WINDOW **_win;
        CpuInfo *_cpu;
        SysInfo *_sys;
        MemInfo *_mem;
        NetInfo *_net;
        winsize _size;
        Display *_controller;

};


void initCurses();
WINDOW **initWindows(WINDOW **board);