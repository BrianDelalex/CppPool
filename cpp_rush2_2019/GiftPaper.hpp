/*
** EPITECH PROJECT, 2020
** giftpaper
** File description:
** header
*/

#ifndef GIFTPAPER_HPP_
#define GIFTPAPER_HPP_

#include "Wrap.hpp"

class GiftPaper : public Wrap {
    public:
        GiftPaper();
        ~GiftPaper();
        bool wrapMeThat(Object *my_Object) override;
        Object *open() override;
    private:
};

#endif