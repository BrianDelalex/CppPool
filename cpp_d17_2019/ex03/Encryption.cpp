/*
** EPITECH PROJECT, 2019
** Encryption.cpp
** File description:
** 
*/

#include "Encryption.hpp"
#include "Cesar.hpp"
#include "OneTime.hpp"
#include "functional"

Encryption::Encryption(IEncryptionMethod &encryptionMethod, void (IEncryptionMethod::*encrypt)(char)) : _encrypt(encrypt), _obj(&encryptionMethod)
{
}

Encryption::~Encryption() {}

void Encryption::operator()(char plainchar)
{
    (this->_obj->*(_encrypt))(plainchar);
}

void Encryption::encryptString(IEncryptionMethod &encryptionMethod, const std::string &toEncrypt)
{
    encryptionMethod.reset();
    std::for_each(toEncrypt.begin(), toEncrypt.end(), Encryption(encryptionMethod, &IEncryptionMethod::encryptChar));
    std::cout << std::endl;
}

void Encryption::decryptString(IEncryptionMethod& encryptionMethod, const std::string &toDecrypt)
{
    encryptionMethod.reset();
    std::for_each(toDecrypt.begin(), toDecrypt.end(), Encryption(encryptionMethod, &IEncryptionMethod::decryptChar));
    std::cout << std::endl;
}