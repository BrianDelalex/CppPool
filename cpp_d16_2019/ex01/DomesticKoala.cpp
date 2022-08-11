/*
** EPITECH PROJECT, 2019
** DomesticKoala.cpp
** File description:
** 
*/

#include "DomesticKoala.hpp"

DomesticKoala::DomesticKoala(KoalaAction &koala)
{
    this->_k = koala;
}

DomesticKoala::~DomesticKoala() {}

DomesticKoala::DomesticKoala(const DomesticKoala &b)
{
    this->_vec = std::vector<methodPointer_t>(*b.getActions());
    this->_k = b.getKoalaAction();
}

DomesticKoala &DomesticKoala::operator=(const DomesticKoala &b)
{
    this->_vec = std::vector<methodPointer_t>(*b.getActions());
    this->_k = b.getKoalaAction();
    return (*this);
}

const std::vector<methodPointer_t> *DomesticKoala::getActions() const
{
    return (&this->_vec);
}

KoalaAction DomesticKoala::getKoalaAction() const
{
    return (this->_k);
}

void DomesticKoala::learnAction(unsigned char command , methodPointer_t action)
{
    this->_commands.push_back(command);
    this->_vec.push_back(action);
}

void DomesticKoala::unlearnAction(unsigned char command)
{
    auto commandIt = this->_commands.begin();
    auto vecIt = this->_vec.begin();

    for (; commandIt != this->_commands.end() && *commandIt != command; commandIt++, vecIt++);
    if (commandIt == this->_commands.end())
        return;
    this->_commands.erase(commandIt);
    this->_vec.erase(vecIt);
}

void DomesticKoala::doAction(unsigned char command, const std:: string &param)
{
    auto commandIt = this->_commands.begin();
    int i =0;

    for (; commandIt != this->_commands.end() && *commandIt != command; commandIt++, i++);
    if (commandIt == this->_commands.end())
        return;
    (this->_k.*(_vec[i]))(param);
}

void DomesticKoala::setKoalaAction(KoalaAction &koala)
{
    this->_k = koala;
    this->_vec.erase(this->_vec.begin(), this->_vec.end());
}