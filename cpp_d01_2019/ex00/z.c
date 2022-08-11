#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

unsigned int find_hex_value(char c)
{
    switch (c) {
        case 'F':
            return (15);
        case 'E':
            return (14);
        case 'D':
            return (13);
        case 'C':
            return (12);
        case 'B':
            return (11);
        case 'A':
            return (10);
        default:
            return ((unsigned int) c - 48 );
    }
}

unsigned int hexa_to_dec(char *hex, unsigned int base)
{
    unsigned int dec = 0;
    unsigned int hexValue;

    for (unsigned int i = 2; hex[i]; i++) {
        int len = strlen(hex + i);
        hexValue = find_hex_value(hex[i]);
        for (unsigned int j = 1; j < len; j++) {
            hexValue = hexValue * base;
        }
        dec = dec + hexValue;
    }
    return (dec);
}

char *my_rev_str(char *str)
{
    int len = strlen(str);
    char *rev = malloc(sizeof(char) * (len + 1));
    int i = 0;
    len -= 1;

     for (; len >= 0; i++, len = len - 1) {
        rev[i] = str[len];
    }
    rev[i] = 0;
    return (rev);
}

char *dec_to_bin(unsigned int dec)
{
    char *bin = malloc(sizeof(char) * 1024);
    int i = 0;
    int len;
    int j = 0;

    while ( dec != 0 ) {
        bin[i] = dec % 2 + 48;
        dec = dec / 2;
        i++;
    }
    bin[i] = '\0';
    return (my_rev_str(bin));
}

int main(int ac, char **av)
{
    printf("z\n");
    return (0);
}