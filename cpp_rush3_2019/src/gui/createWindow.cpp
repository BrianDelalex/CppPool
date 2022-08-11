/*
** EPITECH PROJECT, 2019
**
** File description:
**
*/

#include "environnement.hpp"

sf::RenderWindow *createWindow(unsigned int width, unsigned int height)
{
    sf::RenderWindow *wd = new sf::RenderWindow(sf::VideoMode(width, height), "Hw Monitor");
    wd->setFramerateLimit(33);
    return (wd);
}