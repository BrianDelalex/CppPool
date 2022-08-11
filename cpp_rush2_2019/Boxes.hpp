/*
** EPITECH PROJECT, 2020
** boxes
** File description:
** header
*/

#ifndef BOXES_HPP_
#define BOXES_HPP_

#include "Wrap.hpp"

class Box : public Wrap {
    public:
        Box();
        ~Box();
        bool is_closed(void);
        bool wrapMeThat(Object *my_Object) override;
        void setopcl(bool open);
        Object *open(void) override;
    private:
        bool _is_closed;
};

#endif