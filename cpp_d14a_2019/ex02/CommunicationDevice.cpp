
#include <iostream>
#include <stdexcept>
#include "Errors.hpp"
#include "CommunicationDevice.hpp"

CommunicationDevice::CommunicationDevice(std::istream &input,
                                         std::ostream &output)
    : _api(input, output)
{
    try{}
    catch (const std::exception &e) 
    {
        CommunicationError err(std::string("Error") + e.what());
        throw err;
    }
}

CommunicationDevice::~CommunicationDevice()
{
}

void
CommunicationDevice::startMission(std::string const &missionName,
                                  std::string *users,
                                  size_t nbUsers)
{
    try 
    {
        for (size_t i = 0; i < nbUsers; ++i)
            _api.addUser(users[i]);
        _api.startMission(missionName);
    }
    catch (const std::out_of_range& e)
    {
        CommunicationError err(std::string("LogicError: ") + e.what());
        throw err;
    }
    catch (const std::runtime_error &e)
    {
        CommunicationError err(std::string("RuntimeError: ") + e.what());
        throw err;
    }
    catch (const std::exception &e) 
    {
        CommunicationError err(std::string("Error: ") + e.what());
        throw err;
    }
}

void
CommunicationDevice::send(std::string const &user,
                          std::string const &message) const
{
    try
    {
        _api.sendMessage(user, message);
    } 
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void
CommunicationDevice::receive(std::string const &user,
                             std::string &message) const
{
    try
    {
        _api.receiveMessage(user, message);
    }
    catch(const std::exception& e)
    {
        std::cerr << "INVALID MESSAGE\n";
        throw e;
    }
}
