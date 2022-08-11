/*
** EPITECH PROJECT, 2019
** DomesticKoala.hpp
** File description:
** 
*/

#ifndef DOMESTICKOALA_HPP_
#define DOMESTICKOALA_HPP_

#include "KoalaAction.hpp"
#include <iostream>
#include <vector>

using methodPointer_t = void (KoalaAction::*)(const std::string &param); 

class DomesticKoala
{
public:
    DomesticKoala(KoalaAction &);
    ~DomesticKoala();
    DomesticKoala(const DomesticKoala &);
    DomesticKoala &operator=(const DomesticKoala &);
    const std::vector <methodPointer_t > *getActions() const;
    KoalaAction getKoalaAction() const;
    void learnAction(unsigned char command , methodPointer_t action);
    void unlearnAction(unsigned char command);
    void doAction(unsigned char command, const std:: string &param);
    void setKoalaAction(KoalaAction &);
private:
    std::vector<methodPointer_t> _vec;
    std::vector<unsigned char> _commands;
    KoalaAction _k;
};

#endif
