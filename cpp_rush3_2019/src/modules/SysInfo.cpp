/*
** EPITECH PROJECT, 2019
** SysInfo.cpp
** File description:
** 
*/

#include "SysInfo.hpp"

void setHostname(struct SysInfo *set)
{
    if (gethostname(set->_hostname, 256) != 0)
        set->_hostname = strcpy(set->_hostname, DEFAULT_VALUE_LITTERAL);
}

void setUsername(struct SysInfo *set)
{
    if (getlogin_r(set->_username, 256) != 0)
        set->_username = strcpy(set->_username, DEFAULT_VALUE_LITTERAL);
}

void setOsname(struct SysInfo *set)
{
    if (uname(set->_os) == -1)
        set->_os = DEFAULT_VALUE_NULL;
}

void setDate(struct SysInfo *set)
{
    struct tm *timeinfo;
    time_t current;

    current = time(NULL);
    timeinfo = localtime(&current);
    if (!timeinfo)
        return;
    if (strftime(set->_date, 256,"%d-%m-%Y", timeinfo) == 0)
        set->_date = strcpy(set->_date, DEFAULT_VALUE_LITTERAL);
}

void setTime(struct SysInfo *set)
{
    struct tm *timeinfo;
    time_t current;

    current = time(NULL);
    timeinfo = localtime(&current);
    if (!timeinfo)
        return;
    if (strftime(set->_time, 256, "%H:%M:%S", timeinfo) == 0)
        set->_time = strcpy(set->_time, DEFAULT_VALUE_LITTERAL);
}

struct SysInfo *initSystemInfo(void)
{
    struct SysInfo *sys = getSystemInfo();
    sys->_hostname = new char [256];
    sys->_username = new char [256];
    sys->_date     = new char [256];
    sys->_time     = new char [256];
    sys->_os       = new struct utsname;
    return (sys);
}

struct SysInfo *getSystemInfo(void)
{
    static struct SysInfo *sysinfo = NULL;
    
    if (!sysinfo) {
        sysinfo = new struct SysInfo;
        return (sysinfo);
    }
    setHostname(sysinfo);
    setUsername(sysinfo);
    setDate(sysinfo);
    setTime(sysinfo);
    setOsname(sysinfo);
    return (sysinfo);
}