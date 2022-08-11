/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "environnement.hpp"

int handleEvent(sf::Event &evt, sf::RenderWindow *wd)
{
    while (wd->pollEvent(evt)) {
        if (evt.type == sf::Event::Closed)
            wd->close();
    }
    return (0);
}