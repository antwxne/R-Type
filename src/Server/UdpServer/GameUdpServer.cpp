/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** GameUdpServer
*/

#include "GameUdpServer.hpp"
#include "../GameInstance/GameInstance.hpp"

GameUdpServer::GameUdpServer(GameInstance &gameInstance, int port, int nbPlayers) :
UdpAsioServer(port), _gameMessageHandler(*this), _gameInstance(gameInstance)
{
    _nbPlayers = nbPlayers;
    _bindedPlayers = 0;
}

GameUdpServer::~GameUdpServer()
{
}

void GameUdpServer::run()
{
    while (_running)
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
        if (_bindedPlayers >= _nbPlayers)
        {
            readMessageHeader();
            return false;
        }
        else
        {
            _bindedPlayers++;
            _bindMap[_lastEndpoint] = _bindedPlayers;
        }
    }
    return true;
}

void GameUdpServer::readMessageHeader()
{
    _tmpMessage = Message<MessageType>();

    _socket.async_receive_from(asio::buffer(_tmpMessage.getHeaderPtr(), _tmpMessage.getHeaderSize()), _lastEndpoint,
    [this](std::error_code ec, std::size_t length)
    {
        if (ec)
        {
            readMessageHeader();
            return;
        }
        if (!handlePlayerClient(_lastEndpoint))
            return;

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
    });
}

void GameUdpServer::readMessageBody()
{
    _socket.async_receive_from(asio::buffer(_tmpMessage.getBodyDataPtr(), _tmpMessage.getBodySize()), _lastEndpoint,
    [this](std::error_code ec, std::size_t length)
    {
        if (ec)
        {
            readMessageHeader();
            return;
        }
        _gameMessageList.push_back(GameUdpMessage<MessageType>(_tmpMessage, _bindMap[_lastEndpoint]));
        readMessageHeader();
    });
}

void GameUdpServer::sendMessageToAll(Message<MessageType> &message)
{
    for (auto &i : _bindMap)
    {
        writeMessageHeaderToEndpoint(message, i.first);
    }
}

void GameUdpServer::handleRegister(int nPlayer)
{
    _gameInstance.handleClientRegister(nPlayer);
}

void GameUdpServer::handleClientCommand(int nPlayer, ControlGame control)
{
    _gameInstance.handleClientCommand(nPlayer, control);
}