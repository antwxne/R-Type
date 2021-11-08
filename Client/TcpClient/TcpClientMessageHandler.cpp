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
    _map[MessageType::CreateGame] = &TcpClientMessageHandler::handleCreateGame;
    _map[MessageType::JoinGame] = &TcpClientMessageHandler::handleJoinGame;
    _map[MessageType::LeaveGame] = &TcpClientMessageHandler::handleLeaveGame;
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