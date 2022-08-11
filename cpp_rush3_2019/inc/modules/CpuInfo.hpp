/*
** EPITECH PROJECT, 2019
** CpuInfo.hpp
** File description:
** 
*/

#ifndef CPUINFO_HPP_
#define CPUINFO_HPP_

#include <iostream>
#include <fstream>
#include <string>

#define CPU_INFO_LOCATION "/proc/cpuinfo"

#define CPU_TEMP_LOCATION_PREFIX "/sys/class/thermal/thermal_zone" 
/* from 0 to MAX_CPUS */
#define CPU_TEMP_LOCATION_SUFFIX "/temp"


#define CPU_CORES_KEYWORD     "cpu cores"
#define CPU_FREQ_KEYWORD      "cpu MHz"
#define CPU_VENDOR_ID_KEYWORD "vendor_id"
#define CPU_MODEL_KEYWORD     "model name"

std::string readFile_fromProc(char const *);
void getCpuTemp(struct CpuInfo *);
void getCpuStat(struct CpuInfo *);

struct CpuInfo
{
    std::string _vendor;
    std::string _model;
    std::string _freq;
    std::string _cores;
    std::string _temp;
};

/* get to update information */
struct CpuInfo *getCpuInfo(void);
/* init the object */
struct CpuInfo *initCpuInfo(void);

#endif
