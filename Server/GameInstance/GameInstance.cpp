/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** GameInstance
*/

#include "GameInstance.hpp"

GameInstance::GameInstance(const std::string &instanceName, char maxPlayers) : _name(instanceName),
_maxPlayers(maxPlayers)
{
    _state = WaitingScreen;
    _nbPlayers = 0;
    _run = true;
}

GameInstance::~GameInstance()
{
}

void GameInstance::run()
{
    while (_run)
    {
        std::cout << _name << " Running with " << (int)_nbPlayers << " players\n";
        sleep(1);
    }
}

void GameInstance::stop()
{
    _run = false;
}

std::list<std::string> GameInstance::getPlayers()
{
    std::list<std::string> list;

    for (auto &i : _clients)
        list.push_back(i->informations.getName());
    return list;
}

bool GameInstance::addClient(std::shared_ptr<TcpClientInstance> client)
{
    if (_nbPlayers + 1 > _maxPlayers)
        return false;
    _clients.push_back(client);
    _nbPlayers += 1;
    return true;
}

bool GameInstance::removeClient(std::shared_ptr<TcpClientInstance> client)
{
    auto it = _clients.begin();

    for (; it != _clients.end(); it++)
    {
        if ((*it)->getSocketEndpoint() == client->getSocketEndpoint())
        {
            _clients.erase(it);
            _nbPlayers -= 1;
            return true;
        }
    }
    return false;
}

void GameInstance::removeDisconnectedClient(const std::string &clientName)
{
    auto it = _clients.begin();

    for (; it != _clients.end(); it++)
    {
        if ((*it)->informations.getName() == clientName)
        {
            _nbPlayers -= 1;
        }
    }
}

void GameInstance::startGame()
{
    _state = Game;
}

std::string GameInstance::getName() const
{
    return _name;
}

char GameInstance::getNPlayers() const
{
    return _nbPlayers;
}