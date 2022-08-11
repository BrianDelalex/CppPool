/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include <iostream>

template <typename T>
void print(const T& elem)
{
    std::cout << elem << std::endl;
}

template <typename T>
void foreach(T *array, void (*func)(const T&), size_t size)
{
    for (int i = 0; i < (int) size; i++)
        func(array[i]);
}