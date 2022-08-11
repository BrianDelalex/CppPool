/*
** EPITECH PROJECT, 2019
** Carrier.cpp
** File description:
** 
*/

#include "Carrier.hpp"

Carrier::Carrier(std::string Id) : Attack(100), Toughness(90)
{
    this->Id = Id;
    this->Energy = 300;
    this->Speed = 0;
    for (int i = 0; i < 5; i++)
        this->Droids[i] = nullptr;
}

Carrier::~Carrier() 
{
    for (int i = 0; i < 5; i++) {
        if (this->Droids[i] != nullptr)
            delete this->Droids[i];
    }
}

void Carrier::operator<<(Droid *d)
{
    for (int i = 0; i < 5; i++) {
        if (this->Droids[i] == nullptr) {
            this->Droids[i] = d;
            this->Speed = this->Speed == 0 ? 90 : this->Speed - 10;
            break;
        }
    }
}

void Carrier::operator>>(Droid *d)
{
    for (int i = 0; i < 5; i++) {
        if (this->Droids[i] == d) {
            this->Droids[i] = nullptr;
            this->Speed = this->Speed == 90 ? 0 : this->Speed + 10;
            break;
        }
    }
}

const Droid *Carrier::operator[](const int index) const
{
    if (index < 5)
        return (this->Droids[index]);
    return (nullptr);
}

size_t Carrier::operator~(void)
{
    return (this->Speed);
}

bool Carrier::operator()(const int x, const int y)
{
    int nbOfDroid = 0;
    for (int i = 0; this->Droids[i]; i++)
        nbOfDroid = this->Droids[i] == nullptr ? nbOfDroid : nbOfDroid + 1;
    if (this->Energy < ((abs(x) + abs(y)) * (10 + nbOfDroid)) || this->Speed == 0) {
        return (false);
    }
    this->Energy = this->Energy - ((abs(x) + abs(y)) * (10 + nbOfDroid));
}

Carrier &Carrier::operator<<(size_t &d)
{
    size_t need = 600 - this->Energy;
    if (d >= need) {
        this->Energy = 600;
        d = d - need;
    } else {
        this->Energy += d;
        d = 0;
    }
    return (*this);
}

std::ostream &operator<<(std::ostream &flux, const Carrier &d)
{
    flux << "Carrier '" << d.getId() << "' Droid(s) on-board:\n";
    for (int i = 0; i < 5; i++) {
        if (d[i] != nullptr) {
            flux << "[" << i << "] : " << d[i] << std::endl;
        }
    }
    flux << "Speed : " << d.getSpeed() << ", Energy " << d.getEnergy() << std::endl;
}

size_t Carrier::getEnergy() const
{
    return (this->Energy);
}

size_t Carrier::getSpeed() const
{
    return (this->Speed);
}

size_t Carrier::getId() const
{
    return (this->Id);
}

‘HellExpress’ Droid(s) on-board:$[0] : Droid ‘Commander’, Standing by, 50$[1] : Free$[2] : Free$[3] : Droid ‘Groupie’, Standing by, 50$[4] : Droid ‘BeerHolder’, Standing by, 50$Speed : 70, Energy 222$

