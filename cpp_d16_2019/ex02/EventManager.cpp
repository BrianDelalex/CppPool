/*
** EPITECH PROJECT, 2019
** EventManager.cpp
** File description:
** 
*/

#include "EventManager.hpp"
#include <vector>

EventManager::EventManager()
{
    this->_time = 0;
}

EventManager::~EventManager() {}

EventManager::EventManager(EventManager const &other)
{
    this->_time = other.getTime();
    this->_list = other.getList();
}

EventManager &EventManager::operator=(EventManager const &rhs)
{
    this->_time = rhs.getTime();
    this->_list = rhs.getList();
    return (*this);
}

bool compareEvent(const Event &a, const Event &b)
{
    return (a.getTime() < b.getTime());
}

unsigned int EventManager::getTime() const
{
    return (this->_time);
}

const std::list<Event> &EventManager::getList() const
{
    return (this->_list);
}

void EventManager::addEvent(const Event &e)
{
    if (e.getEvent() == "")
        return;
    if (e.getTime() < this->_time)
        return;
    this->_list.push_back(e);
    this->_list.sort(compareEvent);
}

void EventManager::removeEventsAt(unsigned int time)
{
    std::vector<std::list<Event>::iterator> toRemove;
    for (auto it = this->_list.begin(); it != this->_list.end(); it++)
        if (it->getTime() == time)
            toRemove.push_back(it);
    for (int i = 0; i < (int) toRemove.size(); i++)
        this->_list.erase(toRemove[i]);
    toRemove.clear();
}

void EventManager::dumpEvents() const
{
    for (auto it = this->_list.begin(); it != this->_list.end(); it++)
        std::cout << it->getTime() << ": " << it->getEvent() << std::endl;
}

void EventManager::dumpEventAt(unsigned int time) const
{
    for (auto it = this->_list.begin(); it != this->_list.end(); it++)
    if (it->getTime() == time)
        std::cout << it->getTime() << ": " << it->getEvent() << std::endl;
}

void EventManager::addTime(unsigned int time)
{
    std::vector<std::list<Event>::iterator> toRemove;

    for (auto it = this->_list.begin(); it != this->_list.end(); it++)
    if (it->getTime() >= this->_time && it->getTime() <= this->_time + time) {
        std::cout << it->getEvent() << std::endl;
        toRemove.push_back(it);
    }
    for (int i = 0; i < (int) toRemove.size(); i++)
        this->_list.erase(toRemove[i]);
    toRemove.clear();
    this->_time += time;
}

void EventManager::addEventList(std::list<Event> &events)
{
    for (auto it = events.begin(); it != events.end(); it++)
        if (it->getTime() > this->_time)
            this->_list.push_back(*it);
    this->_list.sort(compareEvent);
}