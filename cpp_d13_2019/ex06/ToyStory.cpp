/*
** EPITECH PROJECT, 2019
** ToyStory.cpp
** File description:
** 
*/

#include "ToyStory.hpp"
#include "Buzz.hpp"
#include "Woody.hpp"

ToyStory::ToyStory()
{
}

ToyStory::~ToyStory() {}

void ToyStory::tellMeAStory(const std::string file, Toy &toy1, bool (Toy::*func1)(const std::string &), Toy &toy2, bool (Toy::*func2)(const std::string &))
{
    std::ifstream stream;
    std::string str;
    bool first = true;

    stream.open(file);
    if (!stream.is_open()) {
        std::cout << "Bad Story" << std::endl;
        stream.close();
        return;
    }
    std::cout << toy1.getAscii() << std::endl;
    std::cout << toy2.getAscii() << std::endl;
    
    Toy::Error e;
    while (std::getline(stream, str, '\n')) {
        if (str.substr(0, 8) == "picture:") {
            if (first) {
                toy1.setAscii(str.substr(8, str.length()));
                e = toy1.getLastError();
                if (e.type == Toy::Error::ErrorType::PICTURE) {
                    std::cout << e.where() << ": " << e.what();
                    break;
                }
                std::cout << toy1.getAscii() << std::endl;
            } else {
                toy2.setAscii(str.substr(8, str.length()));
                e = toy2.getLastError();
                if (e.type == Toy::Error::ErrorType::PICTURE) {
                    std::cout << e.where() << ": " << e.what();
                    break;
                }
                std::cout << toy2.getAscii() << std::endl;
            }
        } else {
            if (first) {
                (toy1.*func1)(str);
                first = !first;
            } else {
                (toy2.*func2)(str);
                first = !first;
            }
        }
    }
    stream.close();
}