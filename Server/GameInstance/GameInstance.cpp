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
    _nbPlayers = 0;
}

GameInstance::~GameInstance()
{
}

void GameInstance::run()
{

}

void GameInstance::setHost(std::shared_ptr<ClientInstance> host)
{
    _host = host;
    _nbPlayers += 1;
}

bool GameInstance::addClient(std::shared_ptr<ClientInstance> client)
{
    if (_nbPlayers + 1 > _maxPlayers)
        return false;
    _clients.push_back(client);
}

virtual GameInstance::void startGame() = 0;