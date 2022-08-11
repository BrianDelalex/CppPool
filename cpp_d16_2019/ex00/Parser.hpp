/*
** EPITECH PROJECT, 2019
** Parser.hpp
** File description:
** 
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>
#include <stack>

class Parser
{
public:
    Parser();
    ~Parser();
    void feed(const std::string &);
    int result() const;
    void reset();
private:
    int resul;
};

#endif
