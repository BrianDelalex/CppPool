/*
** EPITECH PROJECT, 2019
** DroidMemory.cpp
** File description:
** 
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory()
{
    this->Exp = 0;
    this->Fingerprint = random();
}

DroidMemory::DroidMemory(DroidMemory &cpy)
{
    this->Exp = cpy.getExp();
    this->Fingerprint = cpy.getFingerprint();
}

DroidMemory &DroidMemory::operator=(const DroidMemory &b)
{
    this->Exp = b.getExp();
    this->Fingerprint = b.getFingerprint();
    return *this;
}

DroidMemory::~DroidMemory() {}

size_t DroidMemory::getFingerprint() const
{
    return (this->Fingerprint);
}

void DroidMemory::setFingerprint(size_t Fingerprint)
{
    this->Fingerprint = Fingerprint;
}

size_t DroidMemory::getExp() const
{
    return (this->Exp);
}

void DroidMemory::setExp(const size_t Exp)
{
    this->Exp = Exp;
}

void DroidMemory::operator<<(const DroidMemory &b)
{
    this->Exp = this->Exp + b.getExp();
    this->Fingerprint = b.getFingerprint() ^ this->Fingerprint;
}

void DroidMemory::operator>>(DroidMemory &b)
{
    b << *this;
}

void DroidMemory::operator+=(DroidMemory &b)
{
    *this << b;
}

void DroidMemory::operator+=(const size_t b)
{
    this->Exp = this->Exp + b;
    this->Fingerprint = b ^ this->Fingerprint;
}

DroidMemory DroidMemory::operator+(const DroidMemory &b)
{
    DroidMemory a;
    a.setExp(this->Exp + b.getExp());
    a.setFingerprint(b.getFingerprint() ^ this->Fingerprint);
    return (a);
}

std::ostream& operator<<(std::ostream &flux, const DroidMemory &d)
{
    flux << "DroidMemory '" << d.getFingerprint() << "', " << d.getExp();
    return (flux);
}

bool operator==(const DroidMemory &a, const DroidMemory &b)
{
    return (a.getExp() == b.getExp() && a.getFingerprint() == b.getFingerprint());
}

bool operator!=(const DroidMemory &a, const DroidMemory &b)
{
    return (a.getExp() != b.getExp() && a.getFingerprint() != b.getFingerprint());
}

bool operator<(const DroidMemory &a, const DroidMemory &b)
{
    return (a.getExp() < b.getExp());
}

bool operator>(const DroidMemory &a, const DroidMemory &b)
{
    return (a.getExp() > b.getExp());
}

bool operator<=(const DroidMemory &a, const DroidMemory &b)
{
    return (a.getExp() <= b.getExp());
}

bool operator>=(const DroidMemory &a, const DroidMemory &b)
{
    return (a.getExp() >= b.getExp());
}

bool operator==(const DroidMemory &a, const size_t b)
{
    return (a.getExp() == b);
}

bool operator!=(const DroidMemory &a, const size_t b)
{
    return (a.getExp() != b);
}

bool operator<(const DroidMemory &a, const size_t b)
{
    return (a.getExp() < b);
}

bool operator>(const DroidMemory &a, const size_t b)
{
    return (a.getExp() > b);
}

bool operator<=(const DroidMemory &a, const size_t b)
{
    return (a.getExp() <= b);
}

bool operator>=(const DroidMemory &a, const size_t b)
{
    return (a.getExp() >= b);
}