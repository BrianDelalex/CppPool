/*
** EPITECH PROJECT, 2019
** EventManager.hpp
** File description:
** 
*/

#ifndef EVENTMANAGER_HPP_
#define EVENTMANAGER_HPP_

#include "Event.hpp"
#include <list>

class EventManager
{
public:
    EventManager();
    ~EventManager();
    EventManager(EventManager const &other);
    EventManager &operator=(EventManager const &rhs);
    unsigned int getTime() const;
    const std::list<Event> &getList() const;
    void addEvent(const Event &e);
    void removeEventsAt(unsigned int time);
    void dumpEvents() const;
    void dumpEventAt(unsigned int time) const;
    void addTime(unsigned int time);
    void addEventList(std::list<Event> &events);
private:
    unsigned int _time;
    std::list<Event> _list;
};

#endif
