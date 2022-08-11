#include "menger.h"

void loop2(int size, int x, int y)
{
     for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
             print_square(size, i, j, x, y);
        }
    }
}

void loop(t_input *ipt)
{
    int size = ipt->size / 3;
    int lvl = ipt->level - 1;
    int x = 0;
    int y = 0;

    while (lvl > 0 && size >= 3) {
        for (int i = 0; i < 3; i++) {
            y=0;
            for (int j = 0; j < 3 ;j++) {
                if (i != 1 || j != 1) {
                    printf("%03d %03d %03d\n", size / 3, size / 3 + x * size, size / 3 + y * size);
                }
                if (size / 3 >= 3 && (i != 1 || j != 1)) {
                    loop2(size/3, i, j);
                }
                y++;
            }
            x++;
        }
        x=0;
        lvl--;
        size = size/3;
        if ( size == 3) {
            break;
        }
    }
}
         
         
         