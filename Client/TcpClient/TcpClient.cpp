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
    run();
}

void TcpClient::run()
{
    while (true)
    {
        update();
        sleep(0.1);
    }
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
	return true;
}

bool TcpClient::isConnected()
{
    if (!_connection)
        return false;
    return _connection->isConnected();
}

void TcpClient::createGame(const std::string &name)
{
    Message<MessageType> msg;
    char nameC[GAME_NAME_MAX_LENGHT];

    if (isConnected() == false)
    {
        std::cout << "You are not connected" << std::endl;
        return;
    }
    if (name.length() > GAME_NAME_MAX_LENGHT)
    {
        std::cout << "Game Name is " << GAME_NAME_MAX_LENGHT << " length max!" << std::endl;
        return;
    }

    std::strcpy(nameC, name.c_str());
    msg << MessageType::CreateGame;
    msg << nameC;

    sendMessage(msg);
}

void TcpClient::joinGame(const std::string &name)
{
    Message<MessageType> msg;
    char nameC[GAME_NAME_MAX_LENGHT];
    
    if (isConnected() == false)
    {
        std::cout << "You are not connected" << std::endl;
        return;
    }
    if (name.length() > GAME_NAME_MAX_LENGHT)
    {
        std::cout << "Game Name is " << GAME_NAME_MAX_LENGHT << " length max!" << std::endl;
        return;
    }

    std::strcpy(nameC, name.c_str());
    msg << MessageType::JoinGame;
    msg << nameC;

    sendMessage(msg);
}

void TcpClient::leaveGame(const std::string &name)
{
    Message<MessageType> msg;
    char nameC[GAME_NAME_MAX_LENGHT];
    
    if (isConnected() == false)
    {
        std::cout << "You are not connected" << std::endl;
        return;
    }
    if (name.length() > GAME_NAME_MAX_LENGHT)
    {
        std::cout << "Game Name is " << GAME_NAME_MAX_LENGHT << " length max!" << std::endl;
        return;
    }

    std::strcpy(nameC, name.c_str());
    msg << MessageType::LeaveGame;
    msg << nameC;

    sendMessage(msg);
}