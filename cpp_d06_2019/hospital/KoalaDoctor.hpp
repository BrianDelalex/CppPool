/*
** EPITECH PROJECT, 2019
** KoalaDoctor.hpp
** File description:
** 
*/

#ifndef KOALA_DOCTOR_HPP_
#define KOALA_DOCTOR_HPP_

#include "SickKoala.hpp"

class KoalaDoctor
{
public:
    KoalaDoctor(std::string name);
    ~KoalaDoctor();
    std::string diagnose(SickKoala *patient);
    void timeCheck(void);
    std::string getName(void);
private:
    std::string _name;
    bool _start;
};

#endif