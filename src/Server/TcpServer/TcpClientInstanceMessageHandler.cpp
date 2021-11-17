/*
** EPITECH PROJECT, 2021
** B-CPP-500-PAR-5-1-babel-alan.sigal
** File description:
** TcpClientInstanceMessageHandler
*/

#include "TcpClientInstanceMessageHandler.hpp"
#include "TcpClientInstance.hpp"
#include <iostream>
#include "TcpAsioServer.hpp"

typedef void (TcpClientInstanceMessageHandler::*MFP)(TcpClientInstanceMessage<MessageType> &);

TcpClientInstanceMessageHandler::TcpClientInstanceMessageHandler(std::list<std::shared_ptr<TcpClientInstance>> &clientsConnected,
TcpAsioServer &server)
: _clientsConnected(clientsConnected), _server(server)
{
    _map[MessageType::SetPlayerName] = &TcpClientInstanceMessageHandler::handleSetPlayerName;
    _map[MessageType::CreateGame] = &TcpClientInstanceMessageHandler::handleCreateGame;
    _map[MessageType::JoinGame] = &TcpClientInstanceMessageHandler::handleJoinGame;
    _map[MessageType::LeaveGame] = &TcpClientInstanceMessageHandler::handleLeaveGame;
    _map[MessageType::GetGamesList] = &TcpClientInstanceMessageHandler::handleGetGames;
    _map[MessageType::GetPlayersInGame] = &TcpClientInstanceMessageHandler::handleGetPlayersInGame;
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

//Handle Players Response

void TcpClientInstanceMessageHandler::handleSetPlayerName(TcpClientInstanceMessage<MessageType> &message)
{
    char nameC[PLAYER_NAME_MAX_LENGHT];

    try
    {
        message.message >> nameC;

        message.client->informations.setName(nameC);
        writeResponse(message, 200);
    }
    catch(std::exception &e)
    {
        std::cout << "Error handleCreateGAme : " << e.what() << std::endl;
        writeResponse(message, 500);
    }
}

//-----------------------------------------

//Handle Games Responses ----------------------------

void TcpClientInstanceMessageHandler::handleCreateGame(TcpClientInstanceMessage<MessageType> &message)
{
    char nameC[GAME_NAME_MAX_LENGHT];
    
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
        std::cout << "Error handleJoinGAme : " << e.what() << std::endl;
        writeResponse(message, 500);
    }
}

void TcpClientInstanceMessageHandler::handleLeaveGame(TcpClientInstanceMessage<MessageType> &message)
{
    char nameC[GAME_NAME_MAX_LENGHT];

    try
    {
        message.message >> nameC;
        
        if (_server.gamesHandler.leaveGame(nameC, message.client))
            writeResponse(message, 200);
        else
            writeResponse(message, 400);
    }
    catch(std::exception &e)
    {
        std::cout << "Error handleLeaveGAme : " << e.what() << std::endl;
        writeResponse(message, 500);
    }
}


void TcpClientInstanceMessageHandler::handleGetGames(TcpClientInstanceMessage<MessageType> &message)
{
    try
    {
        Message<MessageType> response;
        response << MessageType::GetGamesList;
        response.setResponseCode(200);
        auto l = _server.gamesHandler.getListGames();

        for (auto &i : l)
        {
            char nameC[GAME_NAME_MAX_LENGHT];
            response << i->getNPlayers();
            std::strcpy(nameC, i->getName().c_str());
            response << nameC;
        }
        message.client->sendMessage(response);
    }
    catch(std::exception &e)
    {
        std::cout << "Error handleGetGames : " << e.what() << std::endl;
        writeResponse(message, 500);
    }
}

void TcpClientInstanceMessageHandler::handleGetPlayersInGame(TcpClientInstanceMessage<MessageType> &message)
{
    char gameName[GAME_NAME_MAX_LENGHT];

    message.message >> gameName;

    try
    {
        Message<MessageType> response;
        response << MessageType::GetPlayersInGame;
        response.setResponseCode(200);
        
        auto l = _server.gamesHandler.getPlayersInGame(gameName);

        for (auto &i : l)
        {
            char nameC[PLAYER_NAME_MAX_LENGHT];
            std::strcpy(nameC, i.c_str());
            response << nameC;
        }
        response << gameName;

        message.client->sendMessage(response);
    }
    catch(std::exception &e)
    {
        std::cout << "Error handleGetGames : " << e.what() << std::endl;
        writeResponse(message, 500);
    }
}

//------------------------------------------------