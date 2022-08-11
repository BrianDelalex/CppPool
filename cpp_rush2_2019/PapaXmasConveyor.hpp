/*
** EPITECH PROJECT, 2019
** PapaXmasConveyer.hpp
** File description:
** 
*/

#ifndef PAPAXMASCONVEYER_HPP_
#define PAPAXMASCONVEYER_HPP_

#include "IConveyorBelt.hpp"

class PapaXmasConveyor : public IConveyorBelt
{
public:
    PapaXmasConveyor();
    ~PapaXmasConveyor();
    Object *take();
    void put(Object *obj);
    void setInput(IElf *input);
    void out();
private:
};

#endif
