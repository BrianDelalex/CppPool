/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Object
*/

#include "Object.hpp"
#include "LittlePony.hpp"
#include "Teddy.hpp"
#include "Toy.hpp"
#include "Boxes.hpp"
#include "GiftPaper.hpp"

Object::Object(const std::string &title)
{
    this->_title = title;
}

Object::~Object()
{
}


std::string Object::getTitle() const
{
    return (this->_title);
}

void Object::isTaken()
{
}

Object **UnitTests()
{
    Object **my_objects(new Object *[3]);
    Object *first(new Teddy());
    Object *second(new Box());
    Object *third(new GiftPaper());
    my_objects[0] = first;
    my_objects[1] = second;
    my_objects[2] = third;
    return (my_objects);
}

Object *MyUnitTests(Object **test)
{
    ((Box*)test[1])->wrapMeThat(test[0]);
    ((GiftPaper*)test[2])->wrapMeThat(test[1]);
    return (test[2]);
}
