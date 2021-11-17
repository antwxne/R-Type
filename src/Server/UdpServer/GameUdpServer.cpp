/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** GameUdpServer
*/

#include "GameUdpServer.hpp"

GameUdpServer::GameUdpServer(int port, int nbPlayers) : UdpAsioServer(port)
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
        if (_gameMessageList.size() > 0)
        {
            GameUdpMessage<MessageType> message = _gameMessageList.front();
            _gameMessageList.pop_front();
            _gameMessageHandler.handleMessage(message);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
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

void GameUdpServer::readMessageHeader()
{
    Message<MessageType> message;

    _socket.async_receive_from(asio::buffer(message.getHeaderPtr(), message.getHeaderSize()), _lastEndpoint,
    [this, message](std::error_code ec, std::size_t length) mutable
    {
        if (ec)
        {
            readMessageHeader();
            return;
        }

        handlePlayerClient(_lastEndpoint);

    
        if (message.getBodySize() > 0)
        {
            message.resizeBody(message.getBodySize());
            readMessageBody(message);
        }
        else
        {
            _gameMessageList.push_back(GameUdpMessage<MessageType>(message, _bindMap[_lastEndpoint]));
            readMessageHeader();
        }
    });
}

void GameUdpServer::readMessageBody(Message<MessageType> &message)
{
    _socket.async_receive_from(asio::buffer(message.getBodyDataPtr(), message.getBodySize()), _lastEndpoint,
    [this, message](std::error_code ec, std::size_t length) mutable
    {
        if (ec)
        {
            readMessageHeader();
            return;
        }
        _gameMessageList.push_back(GameUdpMessage<MessageType>(message, _bindMap[_lastEndpoint]));
        readMessageHeader();
    });
}

void GameUdpServer::sendMessageToPlayer(GameUdpMessage<MessageType> &message, int nPlayer)
{
    
}