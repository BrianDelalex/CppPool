/*
** EPITECH PROJECT, 2019
** CpuInfo.cpp
** File description:
** 
*/

#include "CpuInfo.hpp"

std::string readFile_fromProc(char const *file)
{
    std::ifstream fs;
    std::string buffer;

    fs.open(file);
    if (!fs.is_open())
        return (NULL);
    std::getline(fs, buffer, (char)EOF);
    fs.close();
    return (buffer);
}

void getCpuTemp(struct CpuInfo *cpu)
{
    float temp = 0;
    std::ifstream fs;
    std::string buffer;
    std::string openInc;
    int inc = 0;

    while (1) {
        openInc = CPU_TEMP_LOCATION_PREFIX + std::to_string(inc) + CPU_TEMP_LOCATION_SUFFIX;
        fs.open(openInc);
        if (!fs.is_open())
            break;
        std::getline(fs, buffer, (char)EOF);
        if (!buffer.empty()) 
            temp += ((float)stof(buffer)) / 1000.0;
        fs.close();
        inc++;
    }
    cpu->_temp = std::to_string(temp / inc);
}

void getCpuStat(struct CpuInfo *cpuinfo)
{
    std::string read = readFile_fromProc(CPU_INFO_LOCATION);

    size_t idx = read.find(CPU_VENDOR_ID_KEYWORD);
    cpuinfo->_vendor = read.substr(idx, read.find("\n", idx) - idx);
    cpuinfo->_vendor = cpuinfo->_vendor.substr(cpuinfo->_vendor.find_last_of(" ") + 1);

    idx = read.find(CPU_CORES_KEYWORD);
    cpuinfo->_cores = read.substr(idx, read.find('\n', idx) - idx);
    cpuinfo->_cores = cpuinfo->_cores.substr(cpuinfo->_cores.find_last_of(" ") + 1);

    idx = read.find(CPU_FREQ_KEYWORD);
    cpuinfo->_freq = read.substr(idx, read.find('\n', idx) - idx);
    cpuinfo->_freq = cpuinfo->_freq.substr(cpuinfo->_freq.find_last_of(" ") + 1);

    idx = read.find(CPU_MODEL_KEYWORD);
    cpuinfo->_model = read.substr(idx, read.find('\n', read.find(':', idx)) - idx);
    cpuinfo->_model = cpuinfo->_model.substr(cpuinfo->_model.find_first_of(":") + 2);

    // std::cout << cpuinfo->_vendor << "\n";
    // std::cout << cpuinfo->_cores << "\n";
    // std::cout << cpuinfo->_freq << "\n";
    // std::cout << cpuinfo->_model << "\n";
}

struct CpuInfo *initCpuInfo(void)
{
    struct CpuInfo *cpu = getCpuInfo();
    return (cpu);
}

struct CpuInfo *getCpuInfo(void)
{
    static struct CpuInfo *cpuinfo = NULL;
    
    if (!cpuinfo) {
        cpuinfo = new struct CpuInfo;
        return (cpuinfo);
    }
    getCpuTemp(cpuinfo);
    getCpuStat(cpuinfo);
    return (cpuinfo);
}