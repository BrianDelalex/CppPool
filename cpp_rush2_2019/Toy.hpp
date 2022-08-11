/*
** EPITECH PROJECT, 2019
** Toy.hpp
** File description:
** 
*/

#ifndef TOY_HPP_
#define TOY_HPP_
#include "Object.hpp"

class Toy : public Object
{
  public:
    Toy(const std::string &title);
    ~Toy();
    std::string const &getTitle() const;

  private:
};

#endif
