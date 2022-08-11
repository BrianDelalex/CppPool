/*
** EPITECH PROJECT, 2019
**  ex00.c 
** File description:
** 
*/

#include "ex00.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

cthulhu_t *new_cthulhu()
{
    cthulhu_t *new = malloc(sizeof(cthulhu_t));

    cthulhu_initializer(new);
    return (new);
}

void print_power(cthulhu_t *this)
{
    printf("Power => %d\n", this->m_power);
}

void attack(cthulhu_t *this)
{
    if (this->m_power >= 42) {
        this->m_power -= 42;
        printf("%s attacks and destroys the city\n", this->m_name);
    } else {
        printf("%s can't attack, he doesn't have enough power\n", this->m_name);
    }
}

void sleeping(cthulhu_t *this)
{
    printf("%s sleeps\n", this->m_name);
    this->m_power = this->m_power + 42000;
}

koala_t *new_koala(char *name , char is_a_legend)
{
    koala_t *new = malloc(sizeof(koala_t));

    koala_initializer(new, strdup(name), is_a_legend);
    return (new);
}

void eat(koala_t *this)
{
    printf("%s eats\n", this->m_parent.m_name);
    this->m_parent.m_power += 42;
}

static void koala_initializer(koala_t *this, char *_name, char _is_A_Legend)
{
    if (_is_A_Legend == 1) {
        this->m_parent.m_power = 42;
    } else
        this->m_parent.m_power = 0;
    
    this->m_is_a_legend = _is_A_Legend;
    this->m_parent.m_name = _name;
    printf("----\nBuilding Cthulhu\n");
    printf("Building %s\n", _name);
}
static void cthulhu_initializer(cthulhu_t *this)
{
    this->m_name = strdup("Cthulhu");
    this->m_power = 42;
    printf("----\nBuilding Cthulhu\n");
}