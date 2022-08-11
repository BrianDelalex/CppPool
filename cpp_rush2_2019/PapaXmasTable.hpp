/*
** EPITECH PROJECT, 2019
** PapaXmasTable.hpp
** File description:
** 
*/

#ifndef PAPAXMASTABLE_HPP_
#define PAPAXMASTABLE_HPP_

#include "ITable.hpp"

class PapaXmasTable : virtual public ITable
{
public:
    PapaXmasTable();
    ~PapaXmasTable();
    void put(Object *obj);
    Object *take(const std::string &title);
    std::string *look();
private:
};

#endif
