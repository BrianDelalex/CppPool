/*
** EPITECH PROJECT, 2019
** KoalaDoctorList.hpp
** File description:
** 
*/

#ifndef KOALA_DOCTOR_LIST_HPP_
#define KOALA_DOCTOR_LIST_HPP_

#include "KoalaDoctor.hpp"

class KoalaDoctorList
{
public:
    KoalaDoctorList(KoalaDoctor *doc);
    ~KoalaDoctorList();
    bool isEnd(void);
    void append(KoalaDoctorList *ptr);
    KoalaDoctor *getFromName(std::string name);
    KoalaDoctorList *remove(KoalaDoctorList *ptr);
    KoalaDoctorList *removeFromName(std::string name);
    KoalaDoctorList *getNext();
    KoalaDoctor *getContent();
    void dump();
private:
    KoalaDoctorList *current;
    KoalaDoctorList *next;
    KoalaDoctor *value;
};

#endif