/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** GameUdpServer
*/

#include "GameUdpServer.hpp"

GameUdpServer::GameUdpServer(int nbPlayers) : UdpAsioServer(8070)
{
    _nbPlayers = nbPlayers;
    _bindedPlayers = 0;
}

GameUdpServer::~GameUdpServer()
{
}

void GameUdpServer::run()
{
    while (1)
    {
        if (_messageList.size() > 0)
        {
            GameUdpMessage<MessageType> message = _gameMessageList.front();
            _gameMessageList.pop_front();
            _gameMessageHandler.handleMessage(message);
        }
        sleep(0.001);
    }
}

bool GameUdpServer::checkPlayerBinded(asio::ip::udp::endpoint endpoint)
{
    return _bindMap.count(endpoint);
}

bool GameUdpServer::handlePlayerClient(asio::ip::udp::endpoint endpoint)
{
    if (checkPlayerBinded(_lastEndpoint) == false)
    {
        std::cout << "New player!\n";
        if (_bindedPlayers >= _nbPlayers)
        {
            readMessageHeader();
            return false;
        }
        else
        {
            std::cout << "New player binded\n";
            _bindedPlayers++;
            _bindMap[_lastEndpoint] = _bindedPlayers;
        }
    }
    else
    {
        std::cout << "KNowed player\n";
    }
    return true;
}

void GameUdpServer::handleHeaderRecieve(const asio::error_code& error, std::size_t size)
{
    if (error)
    {
        readMessageHeader();
        return;
    }

    handlePlayerClient(_lastEndpoint);

    
    if (_tmpMessage.getBodySize() > 0)
    {
        _tmpMessage.resizeBody(_tmpMessage.getBodySize());
        readMessageBody();
    }
    else
    {
        _gameMessageList.push_back(GameUdpMessage<MessageType>(_tmpMessage, _bindMap[_lastEndpoint]));
        readMessageHeader();
    }
}

void GameUdpServer::handleBodyRecieve(const asio::error_code& error, std::size_t size)
{
    if (error)
    {
        readMessageHeader();
        return;
    }
    _gameMessageList.push_back(GameUdpMessage<MessageType>(_tmpMessage, _bindMap[_lastEndpoint]));
    readMessageHeader();
}

void GameUdpServer::sendMessageToPlayer(GameUdpMessage<MessageType> &message, int nPlayer)
{
    
}