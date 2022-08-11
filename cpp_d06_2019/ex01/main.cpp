/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** my_convert_temp
*/

#include <iostream>
#include <iomanip>
#include "fstream"

int main(int ac, char **av)
{
    std::string str;
    std::stringstream end;
    std::getline(std::cin, str);
    int i = str.find_first_of(" ", 0);
    float value = std::stof(str.substr(0, i), NULL);
    for (; str[i] && str[i] == 32; i++);
    if (str.substr(i, str.length()) == "Celsius") {
        value = 9.0 / 5.0 * value + 32.0;
        end << "        " << value << "        Fahrenheit";
    }
    if (str.substr(i, str.length()) == "Fahrenheit") {
        value = 5.0 / 9.0 * (value - 32.0);
        end << "        " << value << "        Celsius"; 
    }
    std::cout << std::fixed << std::setprecision(3) << std::setw(16) << value;
    if (str.substr(i, str.length()) == "Fahrenheit") {
        std::cout << std::setw(16) << "Celsius" << std::endl;
    }
    if (str.substr(i, str.length()) == "Celsius") {
        std::cout << std::setw(16) << "Fahrenheit" << std::endl;
    }

}