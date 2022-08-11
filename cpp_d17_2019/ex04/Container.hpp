/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

template <typename T>
void aff(const T &a)
{
    std::cout << "Value: " << a << std::endl;
}

template <typename T>
void add(T &a)
{
    a++;
}

template<typename T, template<typename, typename> class U>
class contain
{
public:
    void push(T const &data)
    {
        _container.push_back(data);
    }
    void aff()
    {
        std::for_each(_container.begin(), _container.end(), &::aff<T>);
    }
    void add()
    {
        std::for_each(_container.begin(), _container.end(), &::add<T>);
    }
private:
    U<T, std::allocator<T>> _container;
};