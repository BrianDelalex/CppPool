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
    class Error
    {
        public:
        enum ErrorType
        {
            UNKNOWN,
            PICTURE,
            SPEAK
        };
        Error();
        std::string what() { return (this->_what); }
        std::string where() { return (this->_where); }
        ErrorType type;
        std::string _what;
        std::string _where;
    };
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
    virtual bool speak(const std::string &statement);
    virtual bool speak_es(const std::string &statement);
    const Error getLastError() const;
    Toy &operator<<(const std::string &b);
    protected:
    std::string _name;
    ToyType _type;
    Picture _picture;
    Error _error;
};

std::ostream &operator<<(std::ostream &flux, const Toy &b);

#endif
