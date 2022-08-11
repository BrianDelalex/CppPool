/*
** EPITECH PROJECT, 2019
** RamInfo.cpp
** File description:
** 
*/

#include "MemInfo.hpp"

void getMemoryStat(struct MemInfo *mem)
{
    std::string read = readFile_fromProc(MEM_INFO_LOCATION);

    if (read.empty())
        return;
    size_t idx = read.find(MEM_TOTAL_KEYWORD);
    mem->_totalKB = read.substr(idx, read.find("\n", idx) - idx);
    mem->_totalKB = mem->_totalKB.substr(mem->_totalKB.find_first_of("0123456789"));

    idx = read.find(MEM_FREE_KEYWORD);
    mem->_freeKB = read.substr(idx, read.find("\n", idx) - idx);
    mem->_freeKB = mem->_freeKB.substr(mem->_freeKB.find_first_of("0123456789"));

    idx = read.find(MEM_AVAILABLE_KEYWORD);
    mem->_availableKB = read.substr(idx, read.find("\n", idx) - idx);
    mem->_availableKB = mem->_availableKB.substr(mem->_availableKB.find_first_of("0123456789"));

    long tot = stoi(mem->_availableKB.substr(0, mem->_availableKB.find_first_of(" ")));
    long fre = stoi(mem->_freeKB.substr(0, mem->_freeKB.find_first_of(" ")));
    long used = (fre * 100) / tot;
    used = 100 - used;
    mem->_utilizationPerc = std::to_string(used);
}

struct MemInfo *initMemoryInfo(void)
{
    struct MemInfo *mm = getMemoryInfo();
    return (mm);
}

struct MemInfo *getMemoryInfo(void)
{
    static struct MemInfo *mem = NULL;
    
    if (!mem) {
        mem = new struct MemInfo;
        return (mem);
    }
    getMemoryStat(mem);
    return (mem);
}