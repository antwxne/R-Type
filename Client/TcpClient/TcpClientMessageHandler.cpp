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
    std::cout << "Ok set name\n";
}


//Handle Game Responses

void TcpClientMessageHandler::handleCreateGame(Message<MessageType> &message)
{
    std::cout << "Ok create\n";
}

void TcpClientMessageHandler::handleJoinGame(Message<MessageType> &message)
{
    std::cout << "Ok join\n";
}

void TcpClientMessageHandler::handleLeaveGame(Message<MessageType> &message)
{
    std::cout << "Ok Leave\n";
}

void TcpClientMessageHandler::handleGetGames(Message<MessageType> &message)
{
    int bodysize = message.getBodySize();
    std::cout << "GET GAMES "<< bodysize << "\n";

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
            std::cout << "Game " << name << " with " << (int)nPlayers << " players\n";
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void TcpClientMessageHandler::handleGetPlayersInGame(Message<MessageType> &message)
{
    int bodysize = message.getBodySize();
    std::cout << "GET PLayerInGame "<< bodysize << "\n";

    try
    {
        char gameName[GAME_NAME_MAX_LENGHT];
        message >> gameName;
        std::cout << "Game " << gameName << ":\n";
        bodysize -= GAME_NAME_MAX_LENGHT;
        while (bodysize > 0)
        {
            char name[PLAYER_NAME_MAX_LENGHT];
            message >> name;
            bodysize -= PLAYER_NAME_MAX_LENGHT;
            std::cout << "Player "<< name << "\n";
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}