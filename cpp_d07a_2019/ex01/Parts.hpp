/*
** EPITECH PROJECT, 2019
** Parts.hpp
** File description:
** 
*/

#ifndef PARTS_HPP_
#define PARTS_HPP_

#include <iostream>

class Parts
{
public:
    Parts(std::string serial, bool functional);
    virtual ~Parts();
    virtual bool isFunctional(void) const;
    virtual std::string serial(void) const;
    virtual void informations(void);
    virtual std::string getType(void) const;
protected:
    std::string _serial;
    bool _functional;
    std::string type;
};

class Arms : public Parts
{
public:
    Arms(std::string serial = "A-01", bool functional = true);
    void informations(void);
private:
};

class Legs : public Parts
{
public:
    Legs(std::string serial = "L-01", bool functional = true);
    void informations(void);
private:
};

class Head : public Parts
{
public:
    Head(std::string serial = "H-01", bool functional = true);
    void informations(void);
private:
};


#endif