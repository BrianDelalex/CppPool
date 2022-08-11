/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_
#include <iostream>
#include <iomanip>
#include <string>

class Object
{
  public:
    Object(const std::string &title);
    virtual ~Object();
    std::string getTitle() const;
    virtual void isTaken();

  protected:
    std::string _title;

  private:
};

#endif /* !OBJECT_HPP_ */
