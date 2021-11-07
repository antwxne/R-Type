/*
** EPITECH PROJECT, 2021
** B-CPP-500-PAR-5-1-babel-alan.sigal
** File description:
** TcpClientInstanceMessageHandler
*/

#include "TcpClientInstanceMessageHandler.hpp"
#include "TcpClientInstance.hpp"
#include <iostream>
#include "AsioServer.hpp"

typedef void (TcpClientInstanceMessageHandler::*MFP)(TcpClientInstanceMessage<MessageType> &);

TcpClientInstanceMessageHandler::TcpClientInstanceMessageHandler(std::list<std::shared_ptr<TcpClientInstance>> &clientsConnected,
AsioServer &server)
: _clientsConnected(clientsConnected), _server(server)
{
    _map[MessageType::CreateGame] = &TcpClientInstanceMessageHandler::handleCreateGame;
    _map[MessageType::JoinGame] = &TcpClientInstanceMessageHandler::handleJoinGame;
}

TcpClientInstanceMessageHandler::~TcpClientInstanceMessageHandler()
{
}

void TcpClientInstanceMessageHandler::handleMessage(TcpClientInstanceMessage<MessageType> &message)
{
    MFP fp;
    MessageType messageType = message.message.getMessageType();

    if (_map.find(messageType) == _map.end())
        return;

    fp = _map[messageType];

    return (this->*fp)(message);
}

void TcpClientInstanceMessageHandler::writeResponse(TcpClientInstanceMessage<MessageType> &inMessage, int responseCode)
{
    Message<MessageType> response;

    response << inMessage.message.getMessageType();

    response.setResponseCode(responseCode);

    inMessage.client->sendMessage(response);
}

void TcpClientInstanceMessageHandler::handleCreateGame(TcpClientInstanceMessage<MessageType> &message)
{
    char nameC[GAME_NAME_MAX_LENGHT];

    std::cout << "Create game\n";
    try
    {
        message.message >> nameC;
        
        if (_server.gamesHandler.addGame(nameC, message.client))
            writeResponse(message, 200);
        else
            writeResponse(message, 400);
    }
    catch(std::exception &e)
    {
        std::cout << "Error handleCreateGAme : " << e.what() << std::endl;
        writeResponse(message, 500);
    }
}

void TcpClientInstanceMessageHandler::handleJoinGame(TcpClientInstanceMessage<MessageType> &message)
{
    char nameC[GAME_NAME_MAX_LENGHT];
    std::cout << "Join game\n";

    try
    {
        message.message >> nameC;
        
        if (_server.gamesHandler.joinGame(nameC, message.client))
            writeResponse(message, 200);
        else
            writeResponse(message, 400);
    }
    catch(std::exception &e)
    {
        std::cout << "Error handleCreateGAme : " << e.what() << std::endl;
        writeResponse(message, 500);
    }
}