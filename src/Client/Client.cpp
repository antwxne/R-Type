/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Client
*/

#include "Client.hpp"
#include <chrono>

Client::Client()
{
    _tcpClient.start();
    _stop = false;
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
    while (!_stop)
    {
        _tcpClient.run();
        if (_udpClient)
            _udpClient->run();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void Client::stop()
{
    _tcpClient.stop();
    if (_udpClient)
        _udpClient->stop();
    _stop = true;
}

bool Client::tryConnect(const std::string &ip, int port)
{
    return _tcpClient.tryConnect(ip, port);
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
    char nameC[GAME_NAME_MAX_LENGHT];
    
    if (_tcpClient.isConnected() == false)
    {
        std::cout << "You are not connected" << std::endl;
        return;
    }

    std::strcpy(nameC, name.c_str());
    msg << MessageType::GetPlayersInGame;
    msg << nameC;
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

void Client::startGame(const std::string &name)
{
    Message<MessageType> msg;
    char nameC[GAME_NAME_MAX_LENGHT];
    
    if (_tcpClient.isConnected() == false)
    {
        std::cout << "You are not connected" << std::endl;
        return;
    }
    std::strcpy(nameC, name.c_str());
    msg << MessageType::StartGame;
    msg << nameC;

    _tcpClient.sendMessage(msg);
}

std::list<std::pair<std::string, char>> &Client::getGameList()
{
    return _tcpClient.getGames();
}

void Client::resetGameList()
{
    _tcpClient.resetGameList();
}

std::list<std::string> &Client::getPlayersInGameList()
{
    return _tcpClient.getPlayersInGame();
}

bool Client::isTcpConnected()
{
    return _tcpClient.isConnected();
}

bool Client::isNewGameListAvailable()
{
    return _tcpClient.isNewGameListAvailable();
}

bool Client::isNewPlayerListAvailable()
{
    return _tcpClient.isNewPlayerListAvailable();
}

bool Client::isInGame()
{
    return _tcpClient.isInGame();
}

bool Client::isGameStarting()
{
    return _tcpClient.isGameStarting();
}

int Client::getUdpPort()
{
    return _tcpClient.getUdpPort();
}

void Client::initUdpClient()
{
    if (_tcpClient.isConnected() == false)
    {
        std::cout << "Cannot init UdpClient before connecting to Server" << std::endl;
        return;
    }

    if (getUdpPort() == -1)
    {
        std::cout << "UdpPort not set, the game is not launched" << std::endl;
        return;
    }
    _udpClient = std::make_unique<UdpGameClient>(_tcpClient.getIp(), getUdpPort());
    _udpClient->start();
}
