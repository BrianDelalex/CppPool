/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#ifndef EX05_HPP_
#define EX05_HPP_

#include <string.h>
#include <iostream>

template <typename T>
class array
{
public:
    array()
    {
        this->tab = nullptr;
        this->_size = 0;
    }
    array(unsigned int n)
    {
        this->_size = n;
        if (n > 0)
            this->tab = new T[n]{0};
        else
            this->tab = nullptr;
    }
    array(const array &b)
    {
        if (b._size == 0) {
            this->tab = nullptr;
            this->_size = 0;
        } else {
            this->tab = new T[b._size];
            this->_size = b.size();
            memcpy(this->tab, b.tab, sizeof(T) * b._size);
        }
        
    }
    ~array ()
    {
        if (this->_size != 0)
            delete [] this->tab;
    }
    array &operator=(const array &b)
    {
        if (b._size == 0) {
            this->tab = nullptr;
            this->_size = b._size;
        } else {
            this->tab = new T[b._size]{0};
            this->_size = b._size;
            memcpy(this->tab, b.tab, sizeof(T) * b._size);
        }
        return (*this);
    }
    int size() const
    {
        return (this->_size);
    }
    void *operator new[](size_t size)
    {
        return (new T[size]{0});
    }
    void dump() const
    {
        if (this->_size == 0) {
            std::cout << "[]" << std::endl;
            return;
        }
        std::cout << "[" << this->tab[0];
        for (int i = 1; i < this->_size; i++)
            std::cout << ", " << this->tab[i];
        std::cout << "]\n";
    }
    T &operator[](int index) const
    {
        if (index < this->_size)
            return (this->tab[index]);
        throw std::exception();
    }
    T &operator[](int index)
    {
        if (index < this->_size) {
            return (this->tab[index]);
        }
        try
        {
            T *tab2 = new T[this->_size + 1]{0};
            for (int i = 0; i < this->_size; i++)
                tab2[i] = tab[i];
            if (this->_size != 0)
                delete [] tab;
            this->tab = new T[index + 1]{0};
            for (int i = 0; i < this->_size; i++)
                tab[i] = tab2[i];
            this->_size = index + 1;
            return (this->tab[index]);
        }
        catch(const std::exception& err)
        {
            throw err;
        }
    }
    template <typename U>
    array<U> convertTo(U (*func)(const T&)) const
    {
        array<U> a(this->_size);
        int i = 0;
        for (; i < this->_size; i++)
            a.tab[i] = func(this->tab[i]);
        a._size = this->_size;
        return (a);
    }
    T *tab;
    int _size;
};

template<> void array<bool>::dump() const
    {
        if (this->_size == 0) {
            std::cout << "[]" << std::endl;
            return;
        }
        std::cout << "[";
         if (this->tab[0])
                std::cout << "true";
            else
                std::cout << "false";
        for (int i = 1; i < this->_size; i++) {
            std::cout << ", ";
            if (this->tab[i])
                std::cout << "true";
            else
                std::cout << "false";
        }
        std::cout << "]\n";
    }

#endif