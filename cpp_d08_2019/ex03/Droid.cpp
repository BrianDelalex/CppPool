/*
** EPITECH PROJECT, 2019
** Droid.cpp
** File description:
** 
*/

#include "Droid.hpp"

Droid::Droid(std::string id) : _attack( 25 ), _toughness( 15 )
{
    this->_id = id;
    this->_energy = 50;
    _status = new std::string("Standing by");
    this->BattleData = new DroidMemory();
    std::cout << "Droid '" << this->_id << "' Activated" << std::endl;
}

Droid::~Droid()
{
    std::cout << "Droid '" << this->_id << "' Destroyed" << std::endl;
}

std::string Droid::getId() const
{
    return (this->_id);
}

Droid &Droid::operator=(const Droid &b)
{
    this->_id = b.getId();
    this->_status = new std::string(b.getStatus());
    return *this;
}

bool operator==(const Droid &a, const Droid &b)
{
    return (a.getStatus() == b.getStatus());
}

bool operator!=(const Droid &a, const Droid &b)
{
    return (a.getStatus() != b.getStatus());
}

Droid::Droid(const Droid &cpy) : _attack( 25 ), _toughness( 15 )
{
    this->_id = cpy.getId();
    _status = new std::string(cpy.getStatus());
    this->BattleData = new DroidMemory();
    std::cout << "Droid '" << this->_id << "' Activated, Memory Dumped" << std::endl;
}

size_t Droid::getEnergy(void) const
{
    return (this->_energy);
}
void Droid::setEnergy(size_t energy)
{
    if (energy <= 100)
       this->_energy = energy;
}

size_t Droid::getAttack(void) const
{
    return (this->_attack);
}

size_t Droid::getToughness(void) const
{
    return (this->_toughness);
}

std::string Droid::getStatus(void) const
{
    return (*this->_status);
}

void Droid::setStatus(std::string *status)
{
    if (this->_status != nullptr)
        delete this->_status;
    this->_status = status;
}

void Droid::setId(std::string id)
{
    this->_id = id;
}

std::ostream& operator<<(std::ostream &flux, const Droid &d)
{
    flux << "Droid '" << d.getId() << "', " << d.getStatus() << ", " << d.getEnergy();
    return (flux);
}

Droid &Droid::operator<<(size_t &d)
{
    size_t need = 100 - this->_energy;
    if (d >= need) {
        this->_energy = 100;
        d = d - need;
    } else {
        this->_energy += d;
        d = 0;
    }
    return (*this);
}

DroidMemory *Droid::getBattleData() const
{
    return (this->BattleData);
}

void Droid::setBattleData(DroidMemory *ptr)
{
    this->BattleData = ptr;
}

bool Droid::operator()(const std::string *task, const size_t exp)
{
    if (this->_energy > 10) {
        if (this->BattleData->getExp() >= exp) {
            this->_status = new std::string(*task + " - Completed!");
            this->BattleData->setExp(this->BattleData->getExp() + ( exp / 2 ));
            this->_energy = this->_energy - 10;
            return (true);
        } else {
            this->_status = new std::string(*task + " - Failed!");
            this->BattleData->setExp(this->BattleData->getExp() + exp);
            this->_energy = this->_energy - 10;
            return (false);
        }
    } else {
        this->_energy = 0;
        this->_status = new std::string("Battery Low");
        return (false);
    }
}