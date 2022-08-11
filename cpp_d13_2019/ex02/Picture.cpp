/*
** EPITECH PROJECT, 2019
** Picture.cpp
** File description:
** 
*/

#include "Picture.hpp"

Picture::Picture()
{
    this->data = "";
}

Picture::Picture(const std::string &file)
{
    getPictureFromFile(file);
}

Picture::Picture(const Picture &b)
{
  this->data = std::string(b.data);
}

Picture::~Picture() {}

Picture &Picture::operator=(const Picture &b)
{
    this->data = std::string(b.data);
    return (*this);
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream stream;

    stream.open(file);
    if (!stream.is_open()) {
        this->data = "ERROR";
        return (false);
    }
    std::getline(stream, this->data, (char) EOF);
    return (true);
}