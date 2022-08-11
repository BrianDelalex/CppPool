/*
** EPITECH PROJECT, 2019
** RamInfo.cpp
** File description:
** 
*/

#include "NetInfo.hpp"
#include <fstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/if_link.h>

void getNetRate(struct NetInfo *net)
{
    struct ifaddrs *ifaddr;
    struct ifaddrs *ifa;
    int family, n, inc = 0;

    if (getifaddrs(&ifaddr) == -1)
        return;
    net->_interface[0] = "";
    for (ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++) {
        if (ifa->ifa_addr == NULL)
            continue;
        family = ifa->ifa_addr->sa_family;
        if (family == AF_PACKET && ifa->ifa_data != NULL) {
            for (int i = 0; net->_interface[i] != ""; i++) {
                int first = net->_interface[i].find_first_of(":") + 2;
                std::string tmp = net->_interface[i].substr(first, net->_interface[i].find("\n", first) - first);
                if (tmp == net->_interface[i])
                    continue;
            }
            net->_interface[inc] += "Interface: " + std::string(ifa->ifa_name) + "\n";
            struct rtnl_link_stats *stats = (struct rtnl_link_stats *)ifa->ifa_data;
            net->_interface[inc] += "\tpackets sent = " + std::to_string(stats->tx_packets) + "\n";
            net->_interface[inc] += "\tpackets received = " + std::to_string(stats->rx_packets) + "\n";
            net->_interface[inc] += "\tbytes   sent = " + std::to_string(stats->tx_bytes) + "\n";
            net->_interface[inc] += "\tbytes   received = " + std::to_string(stats->rx_bytes) + "\n";
            net->_interface[inc + 1] = "";
            inc++;
        }
    }
}

struct NetInfo *initNetworkInfo(void)
{
    struct NetInfo *net = getNetworkInfo();
    return (net);
}

struct NetInfo *getNetworkInfo(void)
{
    static struct NetInfo *net = NULL;
    
    if (!net) {
        net = new struct NetInfo;
        return (net);
    }
    getNetRate(net);
    return (net);
}