/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Client
*/

#include "Client.hpp"


Client::Client()
{
}

Client::~Client()
{
}

void Client::start()
{
    run();
}

void Client::run()
{
    while (true)
    {
        sleep(0.1);
    }
}

void Client::sendMessage(Message<MessageType> &message)
{
    if (_connection->isConnected() == false)
    {
        std::cout << "Cannot send message, you are not connected!" << std::endl;
        return;
    }
    _connection->sendMessage(message);
}

bool Client::tryConnect(const std::string &ip, int port)
{
    try
    {
        asio::ip::tcp::resolver resolver(_asioContext);
        asio::ip::tcp::resolver::results_type endpoints = resolver.resolve(ip, std::to_string(port));

        _connection = std::make_unique<ClientConnection>(asio::ip::tcp::socket(_asioContext), _asioContext);

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

bool Client::isConnected()
{
    return _connection->isConnected();
}

void Client::createGame(const std::string &name)
{
    Message<MessageType> msg;
    char nameC[GAME_NAME_MAX_LENGHT];

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

void Client::joinGame(const std::string &name)
{
    Message<MessageType> msg;
    char nameC[GAME_NAME_MAX_LENGHT];
    
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
