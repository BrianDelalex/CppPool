/*
** EPITECH PROJECT, 2019
** NetInfo.hpp
** File description:
** 
*/

#ifndef NETINFO_HPP_
#define NETINFO_HPP_

#include <iostream>

#define NET_LOCATION_BYTE_RECEIVED_PREFIX "/sys/class/net/"
#define NET_LOCATION_BYTE_RECEIVED_SUFFIX "/statistics/tx_bytes"
#define NET_LOCATION_BYTE_SENT_PREFIX     "/sys/class/net/"
#define NET_LOCATION_BYTE_SENT_SUFFIX     "statistics/rx_bytes"

#define NET_LOCATION_DEV "/proc/net/dev"

void getNetworkStat(struct NetInfo *mem);

struct NetInfo
{
    std::string _interface[10];
    std::string _quality;
};

struct NetInfo *initNetworkInfo(void);
struct NetInfo *getNetworkInfo(void);

#endif