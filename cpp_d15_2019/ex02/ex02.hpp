/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include <iostream>

template <typename T>
T min(const T a, const T b)
{
    std::cout << "template min" << std::endl;
    if (a <= b)
        return (a);
    else
        return (b);
}

int min(const int a, const int b)
{
    std::cout << "non-template min" << std::endl;
    if (a <= b)
        return (a);
    else
        return (b);
}

template <typename T>
T templateMin(const T *a, size_t size)
{
    T minim = a[0];
    T rtn;

    for (int i = 0; i + 1 < (int) size; i++) {
        rtn = min<T>(a[i], a[i + 1]);
        minim = rtn < minim ? rtn : minim;
    }
    return (minim);
}

int nonTemplateMin(const int *a, size_t size)
{
    int minim = a[0];
    int rtn;

    for (int i = 0; i  + 1 < (int) size; i++) {
        rtn = min(a[i], a[i + 1]);
        minim = rtn < minim ? rtn : minim;
    }
    return (minim);
}