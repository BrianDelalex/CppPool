/*
** EPITECH PROJECT, 2019
** Event.cpp
** File description:
** 
*/

#include "Event.hpp"

Event::Event()
{
    this->_time = 0;
    this->_task = "";
}

Event::Event(unsigned int time, const std::string &event)
{
    this->_time = time;
    this->_task = event;
}

Event::~Event() {}

Event::Event(const Event &other)
{
    this->_time = other.getTime();
    this->_task = std::string(other.getEvent());
}

Event &Event::operator=(const Event &rhs)
{
    this->_time = rhs.getTime();
    this->_task = std::string(rhs.getEvent());
    return (*this);
}

unsigned int Event::getTime() const
{
    return (this->_time);
}

const std::string &Event::getEvent() const
{
    return (this->_task);
}

void Event::setTime(unsigned int time)
{
    this->_time = time;
}

void Event::setEvent(const std::string &event)
{
    this->_task = event;
}
