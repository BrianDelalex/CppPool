#ifndef MENGER_H_
#define MENGER_H_

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

typedef struct s_input
{
    uint size;
    uint level;
} t_input;

void loop(t_input *ipt);

void print_square(int size, int i, int j, int x, int y);

#endif