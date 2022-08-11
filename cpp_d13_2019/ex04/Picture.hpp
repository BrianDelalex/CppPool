/*
** EPITECH PROJECT, 2019
** Picture.hpp
** File description:
** 
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <iostream>
#include <fstream>

class Picture
{
public:
    Picture();
    Picture(const std::string &file);
    Picture(const Picture &b);
    Picture &operator=(const Picture &b);
    ~Picture();
    bool getPictureFromFile(const std::string &file);
    std::string data;
private:
};

#endif
