/*
** EPITECH PROJECT, 2019
** KreogCom.hpp
** File description:
** 
*/

#ifndef KREOGCOM_HPP_
#define KREOGCOM_HPP_

#include <iostream>

class KreogCom
{
public:
    KreogCom(int x, int y, int serial, KreogCom *list = nullptr);
    ~KreogCom ();
    void addCom(int x, int y, int serial);
    void removeCom();
    KreogCom *getCom();
    void ping();
    void locateSquad();
private:
    const int m_serial;
    const int _x;
    const int _y;
    KreogCom *_link;
};

#endif
