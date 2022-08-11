/*
** EPITECH PROJECT, 2019
** Event.hpp
** File description:
** 
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <iostream>

class Event
{
public:
    Event();
    Event(unsigned int time, const std::string &event);
    ~Event();
    Event(const Event &other);
    Event &operator=(const Event &rhs);
    unsigned int getTime() const;
    const std::string &getEvent() const;
    void setTime(unsigned int time);
    void setEvent(const std::string &event);
private:
    unsigned int _time;
    std::string _task;
};

#endif
