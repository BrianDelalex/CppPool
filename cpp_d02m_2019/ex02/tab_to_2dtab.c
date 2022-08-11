/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** return_intvalue_of_str_argument
*/

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    int **tab2d = malloc(sizeof(int *) * (length));
    int ct = 0;

    for (int i = 0; i < length; i++) {
        tab2d[i] = malloc(sizeof(int) * width);
    }
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            tab2d[i][j] = tab[ct];
            ct++;
        }
    }
    *res = tab2d;
}