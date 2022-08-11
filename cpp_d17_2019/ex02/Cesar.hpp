/*
** EPITECH PROJECT, 2019
** Cesar.hpp
** File description:
** 
*/

#ifndef CESAR_HPP_
#define CESAR_HPP_

#include "IEncryptionMethod.hpp"
#include <iostream>

class Cesar : public IEncryptionMethod
{
public:
    Cesar();
    ~Cesar();
    void encryptChar(char plainchar);
    void decryptChar(char cipherchar);
    void reset();
private:
    int _shift;
};

#endif
