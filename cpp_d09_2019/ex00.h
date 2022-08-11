/*
** EPITECH PROJECT, 2019
** ex00.h
** File description:
** 
*/

typedef struct cthulhu_s
{
    int m_power;
    char *m_name;
} cthulhu_t;

typedef struct koala_s
{
    cthulhu_t m_parent;
    char m_is_a_legend;
} koala_t;

cthulhu_t *new_cthulhu();
void print_power(cthulhu_t *this);
void attack(cthulhu_t *this);
void sleeping(cthulhu_t *this);
koala_t *new_koala(char *name , char is_a_legend);
void eat(koala_t *this);
static void koala_initializer(koala_t *this, char *_name, char _is_A_Legend);
static void cthulhu_initializer(cthulhu_t *this);