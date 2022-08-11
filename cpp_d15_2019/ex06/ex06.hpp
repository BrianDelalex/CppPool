/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include <iostream>
#include <sstream>

template <typename A>
std::string createString(const A &v __attribute__((unused)))
{
    std::stringstream ss;
    ss << "[???]";
    return (ss.str());
}

template<> std::string createString<int>(const int &a)
{
        std::stringstream ss;
        ss << "[int:" << a << "]";
        return ss.str();
}

template<> std::string createString<float>(const float &a)
{
    std::stringstream ss;
    ss << "[float:" << a << "f]";
    return (ss.str());
}

template<> std::string createString(const std::string &a)
{
    std::stringstream ss;
    ss << "[string:\"" << a << "\"]";
    return ss.str(); 
}

template <typename T, typename U = T>
struct Tuple
{
    T a;
    U b;
    std::string toString() const
    {
        std::stringstream ss;
        ss << "[TUPLE " << createString(a) << " " << createString(b) << "]";
        return (ss.str());
    }
};