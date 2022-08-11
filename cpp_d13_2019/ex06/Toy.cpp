/*
** EPITECH PROJECT, 2019
** Toy.cpp
** File description:
** 
*/

#include "Toy.hpp"

Toy::Error::Error()
{
    this->_what = "";
    this->_where = "";
    this->type = UNKNOWN;
}

Toy::Toy()
{
    this->_type = BASIC_TOY;
    this->_picture = Picture();
    this->_name = "toy";
    this->_error = Error();
}

Toy::Toy(Toy::ToyType type, const std::string &name, const std::string &file)
{
    this->_type = type;
    this->_name = name;
    setAscii(file);
}

Toy::Toy(const Toy &b)
{
    this->_picture.data = std::string(b._picture.data);
    this->_type = b.getType();
    this->_name = b.getName();
}

Toy::~Toy() {}

Toy &Toy::operator=(const Toy &b)
{
    this->_picture.data = std::string(b._picture.data);
    this->_type = b.getType();
    this->_name = b.getName();
    return (*this);
}

Toy::ToyType Toy::getType() const { return ( this->_type ); }

std::string Toy::getName() const { return ( this->_name ); }
    
void Toy::setName(const std::string &name) { this->_name = name; }

bool Toy::setAscii(const std::string &file)
{
    if (this->_picture.getPictureFromFile(file) == false) 
    {
        this->_error._what = "bad new illustration";
        this->_error._where = "setAscii";
        this->_error.type = Error::ErrorType::PICTURE;
        return (false);
    }
    return (true);
}

std::string Toy::getAscii() const
{
    return ( this->_picture.data );
}

bool Toy::speak(const std::string &statement)
{
    std::cout << this->_name << " \"" << statement << "\"" << std::endl;
    return (true);
}

bool Toy::speak_es(const std::string &statement)
{
    (void) statement;
    this->_error._what = "wrong mode";
    this->_error._where = "speak_es";
    this->_error.type = Error::ErrorType::SPEAK;
    return (false);
}

const Toy::Error Toy::getLastError() const
{
    return (this->_error);
}

std::ostream &operator<<(std::ostream &flux, const Toy &b)
{
    flux << b.getName() << std::endl << b.getAscii() << std::endl;
    return (flux);
}

Toy &Toy::operator<<(const std::string &b)
{
    this->_picture.data = std::string(b);
    return (*this);
}