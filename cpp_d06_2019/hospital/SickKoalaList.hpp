/*
** EPITECH PROJECT, 2019
** SickKoalaList.hpp
** File description:
** 
*/

#ifndef SICK_KOALA_LIST_HPP
#define SICK_KOALA_LIST_HPP

#include "SickKoala.hpp"

class SickKoalaList
{
public:
    SickKoalaList(SickKoala *ptr);
    ~SickKoalaList();
    bool isEnd(void);
    void append(SickKoalaList *ptr);
    SickKoala *getFromName(std::string name);
    SickKoalaList *remove(SickKoalaList *ptr);
    SickKoalaList *removeFromName(std::string name);
    SickKoala *getContent(void);
    SickKoalaList *getNext(void);
    void dump(void);
    bool is_koala_in(SickKoala *ptr);
private:
    SickKoala *value;
    SickKoalaList *next;
    SickKoalaList *current;
};

#endif
