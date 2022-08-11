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

DroidMemory DroidMemory::operator+(const size_t b)
{
    DroidMemory a;
    a.setExp(this->Exp + b);
    a.setFingerprint(b ^ this->Fingerprint);
    return (a);

}

std::ostream& operator<<(std::ostream &flux, const DroidMemory &d)
{
    flux << "DroidMemory '" << d.getFingerprint() << "', " << d.getExp();
    return (flux);
}