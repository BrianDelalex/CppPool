/*
** EPITECH PROJECT, 2019
** KoalaNurse.cpp
** File description:
** 
*/

#include "KoalaNurse.hpp"
#include <iostream>
#include <fstream>

KoalaNurse::KoalaNurse(int id)
{
    this->_id = id;
    this->_start = false;
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << this->_id << ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *patient)
{
    patient->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string str)
{
    std::string patient = str.substr(0, str.find(".report", 0));
    std::ifstream stream;
    std::string drug;

    stream.open(str);
    if (!stream.is_open()) {
        return (std::string(""));
    }
    std::getline(stream, drug, (char) EOF);
    if (drug.empty()) {
        return (std::string(""));
    }
    std::cout << "Nurse " << this->_id << ": Kreog! Mr." << patient << " needs a " << drug << "!" << std::endl;
    return (drug);
}

void KoalaNurse::timeCheck()
{
    if (!_start) {
        this->_start = true;
        std::cout << "Nurse " << this->_id << ": Time to get to work!" << std::endl;
    } else {
        this->_start = false;
        std::cout << "Nurse " << this->_id << ": Time to go home to my eucalyptus forest!" << std::endl;
    }
}

int KoalaNurse::getID()
{
    return (this->_id);
}