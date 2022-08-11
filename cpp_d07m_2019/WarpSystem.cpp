/*
** EPITECH PROJECT, 2019
** WarpSystem.cpp
** File description:
** 
*/

#include "WarpSystem.hpp"

namespace WarpSystem
{
    QuantumReactor::QuantumReactor()
    {
        this->_stability =  true;
    }

    QuantumReactor::~QuantumReactor() {}

    bool QuantumReactor::isStable()
    {
        return (this->_stability);
    }

    void QuantumReactor::setStability(bool stability)
    {
        this->_stability = stability;
    }

    Core::Core(QuantumReactor *coreReactor)
    {
        this->_coreReactor = coreReactor;
    }

    Core::~Core() {}

    QuantumReactor *Core::checkReactor()
    {
        return (this->_coreReactor);
    }
}
