/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** GameInstancesHandler
*/

#include "GameInstancesHandler.hpp"

GameInstancesHandler::GameInstancesHandler()
{
}

GameInstancesHandler::~GameInstancesHandler()
{
}

void GameInstancesHandler::update()
{
}

void GameInstancesHandler::addGame(const std::string &gameName, std::shared_ptr<ClientInstance> &host)
{
    std::shared_ptr<GameInstance> instance = std::make_shared<GameInstance>(gameName, 4);
    instance->setHost(host);
    _gamesInstances.push_back(instance);
    _gamesThread.push_back(std::thread(&GameInstance::run, instance));
}

bool GameInstancesHandler::joinGame(const std::string &gameName, std::shared_ptr<ClientInstance> &client)
{
    for (auto &i : _gamesInstances)
    {
        if (i->getName() == gameName)
        {
            i->addClient(client);
            return true;
        }
    }
    return false;
}