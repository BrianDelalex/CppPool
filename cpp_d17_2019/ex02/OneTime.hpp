/*
** EPITECH PROJECT, 2019
** OneTime.hpp
** File description:
** 
*/

#ifndef ONETIME_HPP_
#define ONETIME_HPP_

#include "IEncryptionMethod.hpp"
#include <iostream>

class OneTime : public IEncryptionMethod
{
public:
    OneTime(const std::string &key);
    ~OneTime();
    void encryptChar(char plainchar);
    void decryptChar(char cipherchar);
    void reset();
private:
    const std::string _key;
    unsigned int _idx;
    bool crypt;
};

#endif
