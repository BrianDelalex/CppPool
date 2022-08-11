/*
** EPITECH PROJECT, 2019
** OneTime.cpp
** File description:
** 
*/

#include "OneTime.hpp"

#define IS_ALPHA(c) ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
#define IS_CAP(c) (c >= 65 && c <= 90)

OneTime::OneTime(const std::string &key) : _key(key)
{
    this->_idx = 0;
}

OneTime::~OneTime() {}

void OneTime::encryptChar(char plainchar)
{
    int value = IS_CAP(this->_key[this->_idx]) ? this->_key[_idx] - 65 : this->_key[_idx] - 97;
    if (IS_ALPHA(plainchar) && ((plainchar <= 90 && plainchar + value > 90) || plainchar + value > 122))
        std::cout << (char) ((plainchar - 26) + value);
    else if (IS_ALPHA(plainchar))
        std::cout << (char) ((plainchar + value));
    else
        std::cout << (char) plainchar;
    if (this->_idx + 1 == this->_key.length())
        this->_idx = 0;
    else
        this->_idx++;
    this->crypt = true;
}

void OneTime::decryptChar(char cipherchar)
{
    if (this->crypt) {
        this->crypt = false;
        this->_idx = 0;
    }
    int value = IS_CAP(this->_key[this->_idx]) ? this->_key[_idx] - 65 : this->_key[_idx] - 97;
    if (IS_ALPHA(cipherchar) && ((cipherchar >= 97 && cipherchar - value < 97) || cipherchar - value < 65))
        std::cout << (char) ((cipherchar + 26) - value);
    else if (IS_ALPHA(cipherchar))
        std::cout << (char) (cipherchar - value);
    else
        std::cout << (char) cipherchar;
    if (this->_idx + 1 == this->_key.length())
        this->_idx = 0;
    else
        this->_idx++;
}

void OneTime::reset()
{
    this->_idx = 0;
}