/*
** EPITECH PROJECT, 2019
** Teddy.hpp
** File description:
** 
*/

#ifndef TEDDY_HPP_
#define TEDDY_HPP_

#include "Toy.hpp"

class Teddy : virtual public Toy
{
  public:
    Teddy();
    ~Teddy();
    void isTaken();
    std::string *getTitle() const;

  private:
};

#endif
