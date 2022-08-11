/*
** EPITECH PROJECT, 2019
** KreogCom.cpp
** File description:
** 
*/

#include <list>
#include <algorithm>
#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial, KreogCom *link) :  m_serial( serial ), _x( x ), _y( y )
{
    this->_link = link;
    std::cout << "KreogCom " << this->m_serial << " initialized" << std::endl;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << this->m_serial << " shutting down" << std::endl;
}

void KreogCom::addCom(int x, int y, int serial)
{
    if (this->_link == nullptr) {
        this->_link = new KreogCom(x, y, serial);
    } else {
        this->_link = new KreogCom(x, y, serial, this->_link);
    }
}

KreogCom *KreogCom::getCom()
{
    return (this->_link);
}

void KreogCom::removeCom()
{
    if (this->_link != nullptr) {
        KreogCom *toRemove = this->_link;
        this->_link = toRemove->getCom();
        delete toRemove;
    }
}

void KreogCom::ping()
{
    std::cout << "KreogCom " << this->m_serial << " currently at " << this->_x << " " << this->_y << std::endl;
}

void ping_all(KreogCom *kreog)
{
    kreog->ping();
}

void KreogCom::locateSquad()
{
    KreogCom *current = this->_link;
    while (current != nullptr) {
        current->ping();
        current = current->getCom();
    }
    this->ping();
}