/*
** EPITECH PROJECT, 2019
** SysInfo.hpp
** File description:
** 
*/

#ifndef SYSINFO_HPP_
#define SYSINFO_HPP_

#include <iostream>
#include <unistd.h>
#include <sys/utsname.h>
#include <ctime>
#include "string.h"

#define DEFAULT_VALUE_LITTERAL "Unavailable"
#define DEFAULT_VALUE_NULL     NULL

/* 
** struct describing the system informations 
** if they can't be set, they take the default value above
*/

struct SysInfo
{
    char *_hostname;
    char *_username;
    struct utsname *_os; // describe in "sys/utsname" header
    char *_date;
    char *_time;
};

/* get to update information */
struct SysInfo *getSystemInfo(void);
/* init the object */
struct SysInfo *initSystemInfo(void);

void setHostname(struct SysInfo *set);
void setUsername(struct SysInfo *set);
void setDate(struct SysInfo *set);
void setTime(struct SysInfo *set);
void setOsname(struct SysInfo *set);

#endif
