/*
** EPITECH PROJECT, 2019
** KoalaNurse.hpp
** File description:
** 
*/

#ifndef KOALA_NURSE_HPP_
#define KOALA_NURSE_HPP_


#include <iostream>
#include "SickKoala.hpp"

class KoalaNurse
{
public:
    KoalaNurse(int id);
    ~KoalaNurse();
    void giveDrug(std::string drug, SickKoala *patient);
    std::string readReport(std::string str);
    void timeCheck(void);
    int getID(void);
private:
    int _id;
    bool _start;
};

#endif