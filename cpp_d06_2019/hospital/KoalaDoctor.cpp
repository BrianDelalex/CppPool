/*
** EPITECH PROJECT, 2019
** KoalaDoctor.cpp
** File description:
** 
*/

#include "KoalaDoctor.hpp"
#include <iostream>
#include "SickKoala.hpp"
#include <fstream>

KoalaDoctor::KoalaDoctor(std::string name)
{
    this->_name = name;
    this->_start = false;
    std::cout << "Dr."<< this->_name << ": I'm Dr." << name << "! How do you kreog?" << std::endl;
}

KoalaDoctor::~KoalaDoctor() {}

std::string KoalaDoctor::diagnose(SickKoala *patient)
{
    std::string tab[5] = {"Mars", "Buronzand", "Viagra", "Extasy", "Eucalyptus leaf"};
    std::fstream file;

    file.open(patient->getName() + ".report", std::fstream::out);
    std::cout << "Dr." << this->_name << ": So what's goerking you Mr."<< patient->getName() << "?" << std::endl;
    patient->poke();
    file << tab[random() % 5];
    file.close();
    return (patient->getName() + ".report");
}

void KoalaDoctor::timeCheck()
{
    if (!this->_start) {
        this->_start = true;
        std::cout << "Dr." << this->_name << ": Time to get to work!" << std::endl;
    } else {
        this->_start = false;
        std::cout << "Dr." << this->_name << ": Time to go home to my eucalyptus forest!" << std::endl;
    }
}

std::string KoalaDoctor::getName()
{
    return (this->_name);
}