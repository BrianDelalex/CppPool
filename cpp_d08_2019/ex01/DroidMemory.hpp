/*
** EPITECH PROJECT, 2019
** DroidMemory.hpp
** File description:
** 
*/

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

#include <iostream>

class DroidMemory
{
public:
    DroidMemory();
    size_t getFingerprint(void) const;
    void setFingerprint(size_t Fingerprint);
    size_t getExp(void) const;
    void setExp(const size_t Exp);
    void operator<<(const DroidMemory &b);
    void operator>>(DroidMemory &b);
    void operator+=(DroidMemory &b);
    void operator+=(const size_t b);
    DroidMemory operator+(const DroidMemory &b);
    DroidMemory operator+(const size_t b);
    ~DroidMemory();
private:
    size_t Fingerprint;
    size_t Exp;
};

std::ostream& operator<<(std::ostream &flux, const DroidMemory &d);

#endif
