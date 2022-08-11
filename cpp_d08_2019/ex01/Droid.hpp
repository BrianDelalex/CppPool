/*
** EPITECH PROJECT, 2019
** Droid.hpp
** File description:
** 
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include <iostream>
#include "DroidMemory.hpp"

class Droid
{
public:
    Droid(std::string id = std::string(""));
    Droid(Droid &cpy);
    Droid &operator=(Droid &b);
    std::string getId(void) const;
    void setId(std::string id);
    size_t getEnergy(void) const;
    void setEnergy(size_t energy);
    size_t getAttack(void) const;
    size_t getToughness(void) const;
    std::string getStatus(void) const;
    void setStatus(std::string *status);
    void afficher(std::ostream &flux) const;
    void operator<<(size_t &d);
    DroidMemory *getBattleData() const;
    void setBattleData(DroidMemory *ptr);
    ~Droid();

private:
    std::string _id;
    size_t _energy;
    const size_t _attack;
    const size_t _toughness;
    std::string *_status;
    DroidMemory *BattleData;
};

std::ostream& operator<<(std::ostream &flux, const Droid &d);
bool operator!=(const Droid &a, const Droid &b);
bool operator==(const Droid &a, const Droid &b);

#endif
