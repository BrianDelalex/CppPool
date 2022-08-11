/*
** EPITECH PROJECT, 2020
** tablerand
** File description:
** file
*/

#include "Teddy.hpp"
#include "LittlePony.hpp"
#include "Boxes.hpp"
#include "GiftPaper.hpp"
#include "TableRand.hpp"

TableRand::TableRand(): PapaXmasTable()
{
    int random;

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        random = (rand() % 4);
        if (random == 0)
            this->_items[i] = new Teddy;
        else if (random == 1)
            this->_items[i] = new LittlePony;
        else if (random == 2)
            this->_items[i] = new Box;
        else
            this->_items[i] = new GiftPaper;       
    }
    std::cout << "o'pa ere's somin' wron' in da box!" << std::endl;
}

TableRand::~TableRand()
{
    for (int i = 0; i < 10; i++)
        if (_items[i])
            delete _items[i];
}