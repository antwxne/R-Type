/*
** EPITECH PROJECT, 2021
** B-CPP-500-PAR-5-1-babel-alan.sigal
** File description:
** ClientInstanceMessageHandler
*/

#include "ClientInstanceMessageHandler.hpp"
#include "ClientInstance.hpp"
#include <iostream>
#include "TcpServer/AsioServer.hpp"

typedef void (ClientInstanceMessageHandler::*MFP)(ClientInstanceMessage<MessageType> &);

ClientInstanceMessageHandler::ClientInstanceMessageHandler(std::list<std::shared_ptr<ClientInstance>> &clientsConnected,
AsioServer &server)
: _clientsConnected(clientsConnected), _server(server)
{
    _map[MessageType::CreateGame] = &ClientInstanceMessageHandler::handleCreateGame;
    _map[MessageType::JoinGame] = &ClientInstanceMessageHandler::handleJoinGame;
}

ClientInstanceMessageHandler::~ClientInstanceMessageHandler()
{
}

void ClientInstanceMessageHandler::handleMessage(ClientInstanceMessage<MessageType> &message)
{
    MFP fp;
    MessageType messageType = message.message.getMessageType();

    if (_map.find(messageType) == _map.end())
        return;

    fp = _map[messageType];

    return (this->*fp)(message);
}

void ClientInstanceMessageHandler::handleCreateGame(ClientInstanceMessage<MessageType> &message)
{
    char nameC[GAME_NAME_MAX_LENGHT];

    std::cout << "Create game\n";
    message.message >> nameC;
    
    _server.gamesHandler.addGame(nameC, message.client);
}

void ClientInstanceMessageHandler::handleJoinGame(ClientInstanceMessage<MessageType> &message)
{
    char nameC[GAME_NAME_MAX_LENGHT];

    std::cout << "Join game\n";
    message.message >> nameC;

    _server.gamesHandler.joinGame(nameC, message.client);
}