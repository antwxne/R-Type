/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Client
*/

#include "TcpClient.hpp"


TcpClient::TcpClient() : _messageHandler(*this)
{
    _threadContext = std::thread([this]() { _asioContext.run();});
    _newGameList = false;
    _newInGamePlayerList = false;
    _udpPort = -1;
    _isGameStarting = false;
}

TcpClient::~TcpClient()
{

}

void TcpClient::start()
{
}

std::string TcpClient::getIp() const 
{
    return _connection->getIp();
}
void TcpClient::run()
{
    update();
}

void TcpClient::stop()
{
    _asioContext.stop();
    _threadContext.join();
}

void TcpClient::update()
{
    if (_messageList.size() > 0)
    {
        Message<MessageType> message = _messageList.front();
        _messageList.pop_front();
        _messageHandler.handleMessage(message);
    }
}

void TcpClient::sendMessage(Message<MessageType> &message)
{
    if (_connection->isConnected() == false)
    {
        std::cout << "Cannot send message, you are not connected!" << std::endl;
        return;
    }
    _connection->sendMessage(message);
}

bool TcpClient::tryConnect(const std::string &ip, int port)
{
    try
    {
        _ip = ip;
        _port = port;

        asio::ip::tcp::resolver resolver(_asioContext);
        asio::ip::tcp::resolver::results_type endpoints = resolver.resolve(ip, std::to_string(port));

        _connection = std::make_unique<TcpClientConnection>(asio::ip::tcp::socket(_asioContext),
        _asioContext, _messageList);

        _connection->connectToServer(endpoints);
    }

    catch (std::exception& e)
	{
		std::cout << "Cannot connect : " << e.what() << std::endl;
		return false;
	}
	return _connection->isConnected();
}

bool TcpClient::isConnected()
{
    if (!_connection)
        return false;
    return _connection->isConnected();
}


void TcpClient::addGame(const std::string &name, char nbPlayers)
{
    _gamesList.push_back({name, nbPlayers});
}

std::list<std::pair<std::string, char>> &TcpClient::getGames()
{
    _newGameList = false;
    return _gamesList;
}

void TcpClient::resetGameList()
{
    _gamesList.clear();
}

bool TcpClient::isNewGameListAvailable()
{
    return _newGameList;
}

void TcpClient::setGameListAvaible(bool value)
{
    _newGameList = value;
}

void TcpClient::addPlayerInGame(const std::string &name)
{
    _inGamePlayerList.push_back(name);
}

std::list<std::string> &TcpClient::getPlayersInGame()
{
    _newInGamePlayerList = false;
    return _inGamePlayerList;
}

void TcpClient::resetPlayerList()
{
    _inGamePlayerList.clear();
}

bool TcpClient::isNewPlayerListAvailable()
{
    return _newInGamePlayerList;
}
void TcpClient::setPlayerListAvaible(bool value)
{
    _newInGamePlayerList = value;
}

bool TcpClient::isInGame()
{
    return _inGame;
}

void TcpClient::setInGame(bool value)
{
    _inGame = value;
}

bool TcpClient::isGameStarting()
{
    return _isGameStarting;
}

int TcpClient::getUdpPort()
{
    return _udpPort;
}

void TcpClient::setGameStarting(bool value)
{
    _isGameStarting = value;
}

void TcpClient::setUdpPort(int value)
{
    _udpPort = value;
}