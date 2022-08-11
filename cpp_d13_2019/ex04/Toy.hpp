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
    Toy(const Toy &b);
    ~Toy();
    Toy &operator=(const Toy &b);
    enum ToyType{
        BASIC_TOY,
        ALIEN,
        BUZZ,
        WOODY
    };
    Toy(ToyType type, const std::string &name, const std::string &file);
    ToyType getType() const;
    std::string getName() const;
    void setName(const std::string &name);
    bool setAscii(const std::string &file);
    std::string getAscii() const;
    virtual void speak(const std::string &statement);
    Toy &operator<<(const std::string &b);
protected:
    std::string _name;
    ToyType _type;
    Picture _picture;
};

std::ostream &operator<<(std::ostream &flux, const Toy &b);

#endif
