/*
** EPITECH PROJECT, 2019
** Encryption.hpp
** File description:
** 
*/

#ifndef ENCRYPTION_HPP_
#define ENCRYPTION_HPP_

#include "IEncryptionMethod.hpp"
#include <iostream>
#include <algorithm>

class Encryption
{
public:
    Encryption(IEncryptionMethod &encryptionMethod, void (IEncryptionMethod::*encrypt)(char plainchar));
    ~Encryption();
    void operator()(char plainchar);
    static void encryptString(IEncryptionMethod &encryptionMethod, const std::string &toEncrypt);
    static void decryptString(IEncryptionMethod& encryptionMethod, const std::string &toDecrypt);
private:
    void (IEncryptionMethod::*_encrypt)(char plainchar);
    IEncryptionMethod *_obj;
};

#endif
