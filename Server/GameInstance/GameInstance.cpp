/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** GameInstance
*/

#include "GameInstance.hpp"

GameInstance::GameInstance(const std::string &instanceName, int maxPlayers) : _name(instanceName),
_maxPlayers(maxPlayers)
{
    _state = WaitingScreen;
    _nbPlayers = 0;
}

GameInstance::~GameInstance()
{
}

void GameInstance::run()
{
    while (true)
    {
        std::cout << _name << " Running with " << _nbPlayers << " players\n";
        sleep(1);
    }
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

void GameInstance::startGame()
{
    _state = Game;
}

std::string GameInstance::getName()
{
    return _name;
}