/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** TcpClientMessageHandler
*/

#include "TcpClientMessageHandler.hpp"
#include "TcpClient.hpp"

typedef void (TcpClientMessageHandler::*MFP)(Message<MessageType> &);

TcpClientMessageHandler::TcpClientMessageHandler(TcpClient &client) : _client(client)
{
    _map[MessageType::SetPlayerName] = &TcpClientMessageHandler::handleSetName;
    _map[MessageType::CreateGame] = &TcpClientMessageHandler::handleCreateGame;
    _map[MessageType::JoinGame] = &TcpClientMessageHandler::handleJoinGame;
    _map[MessageType::LeaveGame] = &TcpClientMessageHandler::handleLeaveGame;
    _map[MessageType::GetGamesList] = &TcpClientMessageHandler::handleGetGames;
    _map[MessageType::GetPlayersInGame] = &TcpClientMessageHandler::handleGetPlayersInGame;
    _map[MessageType::StartGame] = &TcpClientMessageHandler::handleStartGame;
}

TcpClientMessageHandler::~TcpClientMessageHandler()
{
}

void TcpClientMessageHandler::handleMessage(Message<MessageType> &message)
{
    MFP fp;
    MessageType messageType = message.getMessageType();

    if (_map.find(messageType) == _map.end())
        return;

    fp = _map[messageType];

    return (this->*fp)(message);
}

//Handle Player Responses

void TcpClientMessageHandler::handleSetName(Message<MessageType> &message)
{

}


//Handle Game Responses

void TcpClientMessageHandler::handleCreateGame(Message<MessageType> &message)
{
    if (message.getResponseCode() == 200)
        _client.setInGame(true);
}

void TcpClientMessageHandler::handleJoinGame(Message<MessageType> &message)
{
    if (message.getResponseCode() == 200)
        _client.setInGame(true);
}

void TcpClientMessageHandler::handleLeaveGame(Message<MessageType> &message)
{

}

void TcpClientMessageHandler::handleGetGames(Message<MessageType> &message)
{
    int bodysize = message.getBodySize();

    try
    {
        while (bodysize > 0)
        {
            char name[GAME_NAME_MAX_LENGHT];
            char nPlayers;
            message >> name;
            bodysize -= GAME_NAME_MAX_LENGHT;
            message >> nPlayers;
            bodysize -= sizeof(char);
            _client.addGame(name, nPlayers);
        }
        _client.setGameListAvaible(true);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void TcpClientMessageHandler::handleGetPlayersInGame(Message<MessageType> &message)
{
    int bodysize = message.getBodySize();
    _client.resetPlayerList();

    try
    {
        char gameName[GAME_NAME_MAX_LENGHT];
        message >> gameName;
        bodysize -= GAME_NAME_MAX_LENGHT;
        while (bodysize > 0)
        {
            char name[PLAYER_NAME_MAX_LENGHT];
            message >> name;
            bodysize -= PLAYER_NAME_MAX_LENGHT;
            _client.addPlayerInGame(name);
        }
        _client.setPlayerListAvaible(true);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void TcpClientMessageHandler::handleStartGame(Message<MessageType> &message)
{
    int port;

    message >> port;
    std::cout << "Handle start Game\n";
    _client.setGameStarting(true);
    _client.setUdpPort(port);
}