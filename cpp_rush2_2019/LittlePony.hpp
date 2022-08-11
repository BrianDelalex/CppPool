/*
** EPITECH PROJECT, 2019
** LittlePony.hpp
** File description:
** 
*/

#ifndef LITTLEPONY_HPP_
#define LITTLEPONY_HPP_

#include "Toy.hpp"

class LittlePony : virtual public Toy
{
  public:
    LittlePony();
    ~LittlePony();
    void isTaken();

  private:
};

#endif
