/*
** EPITECH PROJECT, 2019
** SickKoalaList.cpp
** File description:
** 
*/

#include "SickKoalaList.hpp"
#include "SickKoala.hpp"

SickKoalaList::SickKoalaList(SickKoala *ptr)
{
    this->current = this;
    this->value = ptr;
    this->next = nullptr;
}

SickKoalaList::~SickKoalaList() {}

bool SickKoalaList::isEnd()
{
    return (this->next == nullptr);
}

void SickKoalaList::append(SickKoalaList *ptr)
{
    while (this->current->next) {
        this->current = this->current->next;
    }
    this->current->next = ptr;
    this->current = this;
}

SickKoala *SickKoalaList::getFromName(std::string name)
{
    while(this->current) {
        if (this->current->value->getName() == name) {
            SickKoala *ret = this->current->value;
            this->current = this;
            return (ret);
        }
        this->current = this->current->next;
    }
    this->current = this;
    return (nullptr);
}

SickKoalaList *SickKoalaList::remove(SickKoalaList *ptr)
{
    if (this == ptr) {
        return (this->next);
    }
    while (this->current) {
        if (this->current->next == ptr) {
            SickKoalaList *toRemove = this->current->next;
            this->current->next = toRemove->next;
            toRemove->~SickKoalaList();
            this->current = this;
            return (this);
        }
        this->current = this->current->next;
    }
    this->current = this;
    return (nullptr);
}

SickKoalaList *SickKoalaList::removeFromName(std::string name)
{
    if (this->value->getName() == name) {
        return (this);
    }
    while (this->current) {
        if (this->current->next->value->getName() == name) {
            SickKoalaList *toRemove = this->current->next;
            this->current->next = toRemove->next;
            toRemove->~SickKoalaList();
            this->current = this;
            return (this);
        }
    }
    this->current = this;
    return (nullptr);
}

SickKoala *SickKoalaList::getContent()
{
    return (this->value);
}

SickKoalaList *SickKoalaList::getNext()
{
    if (this->next)
        return (this->next);
    return (nullptr);
}

void SickKoalaList::dump()
{
    std::cout << "Patients:";
    while (this->current) {
        std::string name = this->current == nullptr ? "[nullptr]" : this->current->value->getName();
        if (this->current->next)
            std::cout << " " << name << ",";
        else
            std::cout << " " << name << "." << std::endl;
        this->current = this->current->next;
    }
    this->current = this;
}

bool SickKoalaList::is_koala_in(SickKoala *ptr)
{
    while (this->current) {
        if (this->current->getContent() == ptr) {
            this->current = this;
            return (true);
        }
        this->current = this->current->next;
    }
    this->current = this;
    return (false);
}