/*
** EPITECH PROJECT, 2019
** KoalaNurseList.hpp
** File description:
** 
*/

#ifndef KOALA_NURSE_LIST_HPP
#define KOALA_NURSE_LIST_HPP

#include "KoalaNurse.hpp"

class KoalaNurseList
{
public:
    KoalaNurseList(KoalaNurse *ptr);
    ~KoalaNurseList();
    bool isEnd(void);
    void append(KoalaNurseList *ptr);
    KoalaNurse *getContent();
    KoalaNurse *getFromID(int id);
    KoalaNurseList *remove(KoalaNurseList *ptr);
    KoalaNurseList *removeFromID(int id);
    KoalaNurseList *get_next();
    void dump(void);
private:
    KoalaNurse *value;
    KoalaNurseList *current;
    KoalaNurseList *next;
};

#endif