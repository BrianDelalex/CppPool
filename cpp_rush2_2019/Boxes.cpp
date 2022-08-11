/*
** EPITECH PROJECT, 2020
** boxes
** File description:
** file
*/

#include "Boxes.hpp"

Box::Box(): Wrap("Box")
{
    this->_is_closed = false;
}

Box::~Box()
{
}

bool Box::is_closed(void)
{
    return (this->_is_closed);
}

void Box::setopcl(bool status)
{
    this->_is_closed = status;
}

Object *Box::open(void)
{
    if (this->check_containing() == false)
        return nullptr;
    if (this->is_closed() == true)
        this->setopcl(false);
    return (this->contained);    
}

bool Box::wrapMeThat(Object *my_object)
{
    if (!my_object) {
        std::cerr << "The object is empty!" << std::endl;
         return false;
    }
    if (this->is_closed() == true) {
        std::cerr << "Box is not opened" << std::endl;
        return false;
    }
    if (this->check_containing() == true) {
        std::cerr << "Box already contains something" << std::endl;
        return false;
    }
    else {
        this->contained = my_object;
        std::cout << "tuuuut tuuut tuut" << std::endl;
        return true;
    }
}