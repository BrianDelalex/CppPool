#include "menger.h"

int parse_input(t_input *ipt, int ac, char **av)
{
    if ( ac != 3) {
        free(ipt);
        return (84);
    }
    ipt->level = 0;
    ipt->size = 0;
    for (uint i = 0; av[1][i]; i++) {
        ipt->size = ipt->size * 10;
        ipt->size += av[1][i] - 48;
    }
    for (uint i = 0; av[2][i]; i++) {
        ipt->level = ipt->level * 10;
        ipt->level += av[2][i] - 48;
    }
    return (0);
}

void print_square(int size, int i, int j, int x, int y)
{
    if ((i != 1 || j != 1) && (x != 1 || y != 1)) {
        printf("%03d %03d %03d\n", size / 3, size / 3 + i * 3 + x * size *3, size / 3 + j * 3 + y * size * 3, i, j);
    }
}

int main(int ac, char **av)
{
    t_input *ipt = malloc(sizeof(t_input));;
    char **center;
    char **others;
    int level = 1;
    int size;
    
    if (parse_input(ipt, ac, av) == 84) {
        return (84);
    }

    center = malloc(sizeof(char *) * (ipt->size / 3 + 1));
    others = malloc(sizeof(char *) * (ipt->size / 3 + 1));
    printf("%03d %03d %03d\n", ipt->size / 3, ipt->size / 3, ipt->size / 3);
    loop(ipt);
    // if (ipt->level == 0) {
    //     return (0);
    // }
    // size = ipt->size / 3;
    // if (ipt->level - 1 > 0 && ipt->size / 3 >= 3) {
    //     others_square(size , 0, 0, ipt->level - 2);
    // }
}