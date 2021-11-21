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
    srand(time(NULL));
}

GameInstance::~GameInstance()
{
}

void GameInstance::run()
{
    while (_run)
    {
        try
        {
            if (_state == GameInstanceState::Game && _ecs)
                _ecs->run();
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        catch(...) {}
    }
}

void GameInstance::stop()
{
    if (_udpGameServer)
    {
        _udpGameServer->stop();
        _udpThread.join();
    }
    _run = false;
}

std::list<std::string> GameInstance::getPlayers()
{
    std::list<std::string> list;

    for (auto &i : _clients)
    {
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
            _clients.erase(it);
            _nbPlayers -= 1;
            return;
        }
    }
}

void GameInstance::startGame()
{
    _state = Game;

    _udpGameServer = std::make_unique<GameUdpServer>(*this, 0, 4);
    _udpGameServer->start();
    _udpThread  = std::thread([this]() { _udpGameServer->run();});

    sendStartMessages();

    _ecs = std::make_shared<GameInstanceEcs>(*this);
}

void GameInstance::sendStartMessages()
{
    Message<MessageType> startMessage;

    startMessage << MessageType::StartGame;

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

void GameInstance::sendEntityUpdateMessage(const NetworkEntityInformation &info)
{
    Message<MessageType> message;

    message << MessageType::EntityUpdate;

    message << info;

    _udpGameServer->sendMessageToAll(message);
}

void GameInstance::handleClientRegister(int nPlayer)
{
    _ecs->handleNewPlayer(nPlayer);
}

void GameInstance::handleClientCommand(int nPlayer, ControlGame control)
{
    _ecs->handleCommandPlayer(nPlayer, control);
}

void GameInstance::sendEntityRaisedEvent(const std::vector<std::pair<std::size_t, RaisedEvent>> &info)
{

    for (auto &i : info)
    {
        Message<MessageType> message;

        message << MessageType::EntityDestruction;

        message << i.first;
        message << i.second;

        _udpGameServer->sendMessageToAll(message);
    }
}

void GameInstance::sendGameInfos(int score, int round)
{
    Message<MessageType> message;

    message << MessageType::GameInfo;


    message << round;
    message << score;
    
    _udpGameServer->sendMessageToAll(message);
}