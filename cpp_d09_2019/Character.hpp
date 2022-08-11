/*
** EPITECH PROJECT, 2019
** Character.hpp
** File description:
** 
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <iostream>

typedef bool AttackRange;

class Character
{
public:
    Character(const std::string &name, int level);
    ~Character();
    const std::string &getName() const;
    int getLvl() const;
    int getPv() const;
    int getPower() const;
    int CloseAttack();
    void Heal();
    int RangeAttack();
    void RestorePower();
    void TakeDamage(int damage);
    AttackRange Range;
    enum RANGE {
        CLOSE,
        RANGE
    };
protected:
    int CloseAttack2(int nrj, int dmg, std::string display);
    const std::string _name;
    const std::string _race;
    int _level;
    int _health;
    int _power;
    int _stamina;
    int _spirit;
    int _agility;
    int _strenght;
    int _intelligence;
};

#endif
