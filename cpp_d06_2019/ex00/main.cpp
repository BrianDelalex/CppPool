/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** IOStream
*/

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    std::string str;
    if (ac == 1) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
    }
    for (int i = 1; i < ac; i++) {
        std::ifstream file;
        file.open(av[i]);

        if (!file.is_open()) {
            std::cerr << "my_cat: " << av[i] << ": No such file or directory" << std::endl;
            continue;
        }
        std::getline(file, str, (char) EOF);
        std::cout << str;
        file.close();
    }
}