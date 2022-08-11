/*
** EPITECH PROJECT, 2019
** MemInfo.hpp
** File description:
** 
*/

#ifndef RAMINFO_HPP_
#define RAMINFO_HPP_

#include <iostream>
#include "CpuInfo.hpp"

#define MEM_INFO_LOCATION "/proc/meminfo"

#define MEM_AVAILABLE_KEYWORD "MemAvailable: "
#define MEM_TOTAL_KEYWORD     "MemTotal: "
#define MEM_FREE_KEYWORD      "MemFree: "

void getMemoryStat(struct MemInfo *mem);

struct MemInfo
{
    std::string _totalKB;
    std::string _availableKB;
    std::string _freeKB;
    std::string _utilizationPerc;
    std::string _freqPerc;
};

struct MemInfo *initMemoryInfo(void);
struct MemInfo *getMemoryInfo(void);

#endif
