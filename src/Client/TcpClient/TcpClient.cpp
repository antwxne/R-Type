/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Client
*/

#include "TcpClient.hpp"


TcpClient::TcpClient() : _messageHandler(*this)
{
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

        _threadContext = std::thread([this]() { _asioContext.run(); });
    }

    catch (std::exception& e)
	{
		std::cout << "Cannot connect : " << e.what() << std::endl;
		return false;
	}
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
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
    return _gamesList;
}

void TcpClient::resetGameList()
{
    _gamesList.clear();
}