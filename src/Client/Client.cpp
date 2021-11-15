/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Client
*/

#include "Client.hpp"

Client::Client()
{
    _tcpClient.start();
    _udpPort = -1;
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
    while (1)
    {
        _tcpClient.run();
        sleep(0.001);
    }
}

bool Client::tryConnect(const std::string &ip, int port)
{
    return _tcpClient.tryConnect(ip, port);
}


void Client::initUdpClient()
{
    if (_tcpClient.isConnected() == false)
    {
        std::cout << "Cannot init UdpClient before connecting to Server" << std::endl;
        return;
    }

    if (_udpPort == -1)
    {
        std::cout << "UdpPort not set, the game is not launched" << std::endl;
        return;
    }

    _udpClient = std::make_unique<UdpGameClient>(_tcpClient.getIp(), _udpPort);
}


// Game Messages Send
void Client::createGame(const std::string &name)
{
    Message<MessageType> msg;
    char nameC[GAME_NAME_MAX_LENGHT];

    if (_tcpClient.isConnected() == false)
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

    _tcpClient.sendMessage(msg);
}

void Client::joinGame(const std::string &name)
{
    Message<MessageType> msg;
    char nameC[GAME_NAME_MAX_LENGHT];
    
    if (_tcpClient.isConnected() == false)
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

    _tcpClient.sendMessage(msg);
}

void Client::leaveGame(const std::string &name)
{
    Message<MessageType> msg;
    char nameC[GAME_NAME_MAX_LENGHT];
    
    if (_tcpClient.isConnected() == false)
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

    _tcpClient.sendMessage(msg);
}

void Client::getGames()
{
    Message<MessageType> msg;
    
    if (_tcpClient.isConnected() == false)
    {
        std::cout << "You are not connected" << std::endl;
        return;
    }
    msg << MessageType::GetGamesList;
    _tcpClient.sendMessage(msg);
}

void Client::getPlayersInGame(const std::string &name)
{
    Message<MessageType> msg;
    
    if (_tcpClient.isConnected() == false)
    {
        std::cout << "You are not connected" << std::endl;
        return;
    }
    msg << MessageType::GetPlayersInGame;
    _tcpClient.sendMessage(msg);
}

void Client::setPlayerName(const std::string &name)
{
    Message<MessageType> msg;
    char nameC[PLAYER_NAME_MAX_LENGHT];
    
    if (_tcpClient.isConnected() == false)
    {
        std::cout << "You are not connected" << std::endl;
        return;
    }
    std::strcpy(nameC, name.c_str());
    msg << MessageType::SetPlayerName;
    msg << nameC;

    _tcpClient.sendMessage(msg);
}