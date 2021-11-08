/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** GameInstancesHandler
*/

#include "GameInstancesHandler.hpp"

GameInstancesHandler::GameInstancesHandler(int maxGames) : _maxGames(maxGames)
{
}

GameInstancesHandler::~GameInstancesHandler()
{
}

void GameInstancesHandler::update()
{
}

bool GameInstancesHandler::addGame(const std::string &gameName, std::shared_ptr<TcpClientInstance> &host)
{
    if (_nbGames + 1 >= _maxGames)
        return false;
    
    std::shared_ptr<GameInstance> instance = std::make_shared<GameInstance>(gameName, 4);
    instance->addClient(host);

    _gamesInstances.push_back(instance);
    _gamesThread.push_back(std::thread(&GameInstance::run, instance));

    _nbGames++;
    return true;
}

bool GameInstancesHandler::joinGame(const std::string &gameName, std::shared_ptr<TcpClientInstance> &client)
{
    for (auto &i : _gamesInstances)
    {
        if (i->getName() == gameName)
        {
            if (i->addClient(client))
                return true;
            else
                return false;
        }
    }
    return false;
}


bool GameInstancesHandler::leaveGame(const std::string &gameName, std::shared_ptr<TcpClientInstance> &client)
{
    for (auto &i : _gamesInstances)
    {
        if (i->getName() == gameName)
        {
            if (i->removeClient(client))
                return true;
            else
                return false;
        }
    }
    return false;
}