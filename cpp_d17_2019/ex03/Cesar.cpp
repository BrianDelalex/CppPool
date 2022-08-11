/*
** EPITECH PROJECT, 2019
** Cesar.cpp
** File description:
** 
*/

#include "Cesar.hpp"

#define IS_ALPHA(c) ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))

Cesar::Cesar()
{
    this->_shift = 3;
}

Cesar::~Cesar() {}

void Cesar::encryptChar(char plainchar)
{
    if (IS_ALPHA(plainchar) && ((plainchar <= 90 && plainchar + this->_shift > 90) || plainchar + this->_shift > 122))
        std::cout << (char) ((plainchar - 26) + this->_shift);
    else if (IS_ALPHA(plainchar))
        std::cout << (char) (plainchar + this->_shift);
    else
        std::cout << (char) (plainchar);
    this->_shift++;
    if (this->_shift > 28)
        this->_shift = 3;
    
    
}

void Cesar::decryptChar(char cipherchar)
{
    if (IS_ALPHA(cipherchar) && ((cipherchar >= 97 && (cipherchar - this->_shift) < 97) || (cipherchar - this->_shift) < 65))
        std::cout << (char) ((cipherchar + 26) - this->_shift);
    else if (IS_ALPHA(cipherchar))
        std::cout << (char) (cipherchar - this->_shift);
    else
        std::cout << (char) (cipherchar);
    this->_shift++;
    if (this->_shift > 28)
        this->_shift = 3;

}

void Cesar::reset()
{
    this->_shift = 3;
}