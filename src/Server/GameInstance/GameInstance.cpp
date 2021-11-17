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
        if (_udpGameServer)
            _udpGameServer->run();
        //std::cout << _name << " Running with " << (int)_nbPlayers << " players\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void GameInstance::stop()
{
    _run = false;
}

std::list<std::string> GameInstance::getPlayers()
{
    std::list<std::string> list;
    std::cout << "getPlayer\n";


    for (auto &i : _clients)
    {
        std::cout << "omg new player\n";
        list.push_back(i->informations.getName());
    }
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

    _udpGameServer = std::make_unique<GameUdpServer>(0, 4);

    Message<MessageType> startMessage;

    startMessage << MessageType::UdpGetPort;

    startMessage << _udpGameServer->getPort();

    for (auto &i : _clients)
    {
        i->sendMessage(startMessage);
    }
}

std::string GameInstance::getName() const
{
    return _name;
}

char GameInstance::getNPlayers() const
{
    return _nbPlayers;
}