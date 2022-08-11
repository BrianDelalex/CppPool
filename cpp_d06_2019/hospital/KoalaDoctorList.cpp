/*
** EPITECH PROJECT, 2019
** KoalaDoctorList.cpp
** File description:
** 
*/

#include "KoalaDoctorList.hpp"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *doc)
{
    this->value = doc;
    this->current = this;
    this->next = nullptr;
}

KoalaDoctorList::~KoalaDoctorList() {}

bool KoalaDoctorList::isEnd()
{
    return (this->next == nullptr);
}

void KoalaDoctorList::append(KoalaDoctorList *ptr)
{
    while (this->current->next) {
        this->current = this->current->next;
    }
    this->current->next = ptr;
    this->current = this;
}

KoalaDoctor *KoalaDoctorList::getFromName(std::string name)
{
    while(this->current) {
        if (this->current->value->getName() == name) {
            KoalaDoctor *ret = this->current->value;
            this->current = this;
            return (ret);
        }
        this->current = this->current->next;
    }
    this->current = this;
    return (nullptr);
}

KoalaDoctorList *KoalaDoctorList::remove(KoalaDoctorList *ptr)
{
    if (this == ptr) {
        return (this->next);
    }
    while (this->current) {
        if (this->current->next == ptr) {
            KoalaDoctorList *toRemove = this->current->next;
            this->current->next = toRemove->next;
            toRemove->~KoalaDoctorList();
            this->current = this;
            return (this);
        }
        this->current = this->current->next;
    }
    this->current = this;
    return (nullptr);
}

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string name)
{
    if (this->value->getName() == name) {
        return (this);
    }
    while (this->current) {
        if (this->current->next->value->getName() == name) {
            KoalaDoctorList *toRemove = this->current->next;
            this->current->next = toRemove->next;
            toRemove->~KoalaDoctorList();
            this->current = this;
            return (this);
        }
    }
    this->current = this;
    return (nullptr);
}

KoalaDoctor *KoalaDoctorList::getContent()
{
    return (this->value);
}

KoalaDoctorList *KoalaDoctorList::getNext()
{
    if (this->next)
        return (this->next);
    return (nullptr);
}

void KoalaDoctorList::dump()
{
    std::cout << "Doctors:";
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