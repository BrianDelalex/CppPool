/*
** EPITECH PROJECT, 2019
** Toy.hpp
** File description:
** 
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include <iostream>
#include "Picture.hpp"

class Toy
{
public:
    Toy();
    ~Toy();
    enum ToyType{
        BASIC_TOY,
        ALIEN
    };
    Toy(ToyType type, const std::string &name, const std::string &file);
    ToyType getType() const;
    std::string getName() const;
    void setName(const std::string &name);
    bool setAscii(const std::string &file);
    std::string getAscii() const;

private:
    std::string _name;
    ToyType _type;
    Picture _picture;
};

#endif
