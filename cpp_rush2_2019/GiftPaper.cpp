/*
** EPITECH PROJECT, 2020
** giftpaper
** File description:
** file
*/

#include "GiftPaper.hpp"

GiftPaper::GiftPaper(): Wrap("GiftPaper")
{
}

GiftPaper::~GiftPaper()
{
}

bool GiftPaper::wrapMeThat(Object *my_object)
{
    if (!my_object) {
        std::cerr << "Object is empty!" << std::endl;
        return false;
    }
    if (this->check_containing() == true) {
        std::cerr << "GiftPaper already contains something" << std::endl;
        return false;
    }
    else {
        this->contained = my_object;
        std::cout << "tuuuut tuuut tuut" << std::endl;
        return true;
    }
}

Object *GiftPaper::open()
{
    if (this->check_containing() == false)
        return nullptr;
    return (this->contained);
}