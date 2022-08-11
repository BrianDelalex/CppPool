/*
** EPITECH PROJECT, 2020
** wrap
** File description:
** file
*/

#include "Wrap.hpp"
#include "Boxes.hpp"
#include "GiftPaper.hpp"

Wrap::Wrap(std::string name): Object(name) 
{
    std::cout << "whistles while working" << std::endl;
    this->contains_smth = false;
    this->contained = nullptr;
}

Wrap::~Wrap()
{
}

bool Wrap::check_containing(void)
{
    return (this->contains_smth);
}
