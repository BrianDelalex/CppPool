/*
** EPITECH PROJECT, 2019
** Parser.cpp
** File description:
** 
*/

#include "Parser.hpp"
#include <vector>

Parser::Parser()
{
    resul = 0;
}

Parser::~Parser() {}

int calc(int a, int b, char op)
{
    if (op == '-')
        return (a - b);
    else if (op == '+')
        return (a + b);
    else if (op == '/')
        return (a / b);
    else if (op == '%')
        return (a % b);
    else if (op == '*')
        return (a * b);
    return (0);
}

#define OPERATOR(c) (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')

void Parser::feed(const std::string &op)
{
    std::string ope;
    std::vector<std::string> numbers;

    for (int i = 0; i < (int)op.length(); i++) {
        if (op[i] >= 48 && op[i] <= 57) {
            std::string nb;
            for (; op[i] && op[i] >= 48 && op[i] <= 57; i++)
                nb += op[i];
            i--;
            numbers.push_back(nb);
        }
        else if (OPERATOR(op[i]) && ope.size() == 0 ) {
            ope.push_back(op[i]);
        }
        else if (OPERATOR(op[i]) && ope.size() != 0 && ope.find_first_of("(") == std::string::npos) {
            std::string push;
            push += ope.back();
            ope.pop_back();
            numbers.push_back(push);
            ope.push_back(op[i]);
        }
        else if (op[i] == '(') {
            ope += op[i];
        }
        else if (OPERATOR(op[i]))
        {
            ope += op[i];
        }
        else if (op[i] == ')') {
            while (ope.back() != '(' ){
                std::string str = "";
                if (ope.back() != '(') {
                    str += ope.back();
                    numbers.push_back(str);
                    str = "";
                }
                ope.pop_back();
            }
            ope.pop_back();
        }
    }
    while(!ope.empty()) {
        std::string str = "";
        if (ope.back() != '(') {
            str += ope.back();
            numbers.push_back(str);
            str = "";
        }
        ope.pop_back();
    }
    int i = 0;
    while ((int)numbers.size() > 1)
    {
        for (i= 0; i < (int)numbers.size() && !OPERATOR(numbers[i].back()); i++);
        int left = std::stoi(numbers[i - 2]);
        int right = std::stoi(numbers[i - 1]);
        std::vector<std::string>::iterator leftIt = numbers.begin() + (i - 2);
        std::vector<std::string>::iterator rightIt = numbers.begin() + (i);
        int value = calc(left, right, numbers[i].back());
        numbers[i] = std::to_string(value);
        numbers.erase(leftIt, rightIt);
    }
    
    this->resul += std::stoi(numbers[0]);
}

int Parser::result() const
{
    return (this->resul);
}

void Parser::reset()
{
    this->resul = 0;
}