/*
** EPITECH PROJECT, 2019
** WarpSystem.hpp
** File description:
** 
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

namespace WarpSystem
{

    class QuantumReactor
    {
    public:
        QuantumReactor(void);
        ~QuantumReactor(void);
        bool isStable(void);
        void setStability(bool stability);
    private:
        bool _stability;
    };

    class Core
    {
    public:
        Core(QuantumReactor *coreReactor);
        ~Core();
        QuantumReactor *checkReactor(void);
    private:
        QuantumReactor *_coreReactor;
    };

}

#endif
