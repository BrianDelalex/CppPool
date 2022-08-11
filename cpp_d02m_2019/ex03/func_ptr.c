/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** return_intvalue_of_str_argument
*/

#include "func_ptr.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    int len = strlen(str);
    char *rev = malloc(sizeof(char) * (len + 1));
    int i = 0;

    len -= 1;
     for (; len >= 0; i++, len = len - 1) {
        rev[i] = str[len];
    }
    rev[i] = 0;
    printf("%s\n", rev);
}

void print_upper(const char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 97 && str[i] <= 122) {
            printf("%c", str[i] - 32);
        } else {
            printf("%c", str[i]);
        }
    }
    printf("\n");
}

void print_42(__attribute__((unused)) const char *str)
{
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void *func_tab[4] = {&print_normal, &print_reverse, &print_upper, &print_42};
    void (*fptr)(const char *);

    fptr = func_tab[action];
    fptr(str);
}