/*
** EPITECH PROJECT, 2020
** wrap
** File description:
** header
*/

#ifndef WRAP_HPP_
#define WRAP_HPP_

#include <string>
#include <iostream>

#include "Object.hpp"

class Wrap : public Object {
    public:
        Wrap(const std::string name);
        ~Wrap();
        virtual bool wrapMeThat(Object *my_object) = 0;
        virtual Object *open(void) = 0;
        bool check_containing(void);
    protected:
        bool contains_smth;
        Object *contained;
};

#endif