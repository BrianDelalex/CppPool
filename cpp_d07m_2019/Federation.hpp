/*
** EPITECH PROJECT, 2019
** Federation.hpp
** File description:
** 
*/

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

#include <iostream>
#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Borg.hpp"

namespace Federation
{
        class Federation
        {
        public:
            Federation();
            ~Federation();
        };
        class Ship
        {
        public:
            Ship(int length, int width, std:: string name);
            ~Ship();
            void setupCore(WarpSystem::Core *coreReactor);
            void checkCore(void);
            bool move(int warp , Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move();
            WarpSystem::Core *getCore(void);
        private:
            int _lenght;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_coreReactor;
            Destination _location;
            Destination _home;
        };

    namespace Starfleet
    {
        class Captain
        {
        public:
            Captain(std::string name);
            ~Captain();
            std::string getName(void);
            int getAge(void);
            void setAge(int age);
        private:
            std::string _name;
            int _age;
        };

        class Ship
        {
        public:
            Ship(int length, int width, std:: string name, short maxWarp , int torpedo = 0);
            Ship();
            ~Ship();
            void setupCore(WarpSystem::Core *coreReactor);
            void checkCore(void);
            void promote(Captain *captain);
            bool move(int warp , Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move(void);
            int getShield(void);
            void setShield(int shield);
            int getTorpedo(void);
            void setTorpedo(int torpedo);
            void fire(Borg::Ship *target);
            void fire(int torpedoes, Borg::Ship *target);
        private:
            int _lenght;
            int _width;
            std::string _name;
            short _maxWarp;
            WarpSystem::Core *_coreReactor;
            Captain *_captain;
            Destination _location;
            Destination _home;
            int _shield;
            int _photonTorpedo;
        };

        class Ensign
        {
        public:
            Ensign(std::string name);
            ~Ensign();
        private:
            std::string _name;
        };
    }
}
#endif
