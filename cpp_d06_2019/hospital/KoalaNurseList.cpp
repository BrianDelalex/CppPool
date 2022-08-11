/*
** EPITECH PROJECT, 2019
** KoalaNurseList.cpp
** File description:
** 
*/

#include "KoalaNurseList.hpp"
#include "KoalaNurse.hpp"

KoalaNurseList::KoalaNurseList(KoalaNurse *ptr)
{
    this->value = ptr;
    this->current = this;
    this->next = nullptr;
}

KoalaNurseList::~KoalaNurseList() {}

bool KoalaNurseList::isEnd()
{
    return (this->next == NULL);
}

void KoalaNurseList::append(KoalaNurseList *ptr)
{
    while (this->current->next) {
        this->current = this->current->next;
    }
    this->current->next = ptr;
    this->current = this;
}

KoalaNurse *KoalaNurseList::getFromID(int id)
{
    while (this->current) {
        if (this->current->value->getID() == id) {
            KoalaNurse *rtn = this->current->value;
            this->current = this;
            return (rtn);
        }
        this->current = this->current->next;
    }
    this->current = this;
    return (nullptr);
}

KoalaNurseList *KoalaNurseList::remove(KoalaNurseList *ptr)
{
    if (this == ptr) {
        return (this->next);
    }
    while (this->current) {
        if (this->current->next == ptr) {
            KoalaNurseList *toRemove = this->current->next;
            this->current->next = toRemove->next;
            toRemove->~KoalaNurseList();
            this->current = this;
            return (this);
        }
    }
    this->current = this;
    return (this);
}

KoalaNurseList *KoalaNurseList::removeFromID(int id)
{
    if (this->value->getID() == id) {
        return (this->next);
    }
    while (this->current) {
        if (this->current->next->value->getID() == id) {
            KoalaNurseList *toRemove = this->current->next;
            this->current->next = toRemove->next;
            toRemove->~KoalaNurseList();
            this->current = this;
            return (this);
        }
    }
    this->current = this;
    return (this);
}

KoalaNurseList *KoalaNurseList::get_next()
{
    return (this->next);
}

void KoalaNurseList::dump()
{
    std::cout << "Nurses:";
    while (this->current) {
        if (this->current == nullptr)
            std::cout << "[nullptr]";
        else if (this->current->next)
            std::cout << " " << this->current->value->getID() << ",";
        else
            std::cout << " " << this->current->value->getID() << "." << std::endl;
        this->current = this->current->next;
    }
    this->current = this;
}

KoalaNurse *KoalaNurseList::getContent()
{
    return (this->value);
}