/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

template<typename T>
typename T::iterator do_find(T &ref, int x)
{
    return (std::find(ref.begin(), ref.end(), x));
}