/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include "Errors.hpp"

NasaError::NasaError(std::string const &message, std::string const &component) : exception()
{
    this->_message = message;
    this->_component = component;
}

std::string const &NasaError::getComponent() const
{
    return (this->_component);
}

MissionCriticalError::MissionCriticalError(std::string const &message, std::string const &component) : NasaError(message, component)
{
}

LifeCriticalError::LifeCriticalError(std::string const &message, std::string const &component) : NasaError(message, component)
{
}

UserError::UserError(std::string const &message, std::string const &component) : NasaError(message, component)
{
}

CommunicationError::CommunicationError(std::string const &message) : NasaError(message, "communicationDevice")
{
}

std::string const &CommunicationError::getComponent() const
{
    return (this->_component);
}

