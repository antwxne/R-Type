/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** UdpGameMessageHandler
*/

#include "UdpGameMessageHandler.hpp"
#include "Graphical/SfmlEventFactory.hpp"
#include "GameUdpMessage.hpp"
#include "GameUdpServer.hpp"

typedef void (UdpGameMessageHandler::*UdpMFP)(GameUdpMessage<MessageType> &);

UdpGameMessageHandler::UdpGameMessageHandler(GameUdpServer &server) : _server(server)
{
    _map[MessageType::GameCommand] = &UdpGameMessageHandler::handleCommand;
    _map[MessageType::GameRegister] = &UdpGameMessageHandler::handleRegister;
}

UdpGameMessageHandler::~UdpGameMessageHandler()
{
}

void UdpGameMessageHandler::handleMessage(GameUdpMessage<MessageType> &message)
{
    UdpMFP fp;
    MessageType messageType = message.message.getMessageType();

    if (_map.find(messageType) == _map.end())
        return;

    fp = _map[messageType];

    return (this->*fp)(message);
}

void UdpGameMessageHandler::handleCommand(GameUdpMessage<MessageType> &message)
{
    ControlGame control;

    message.message >> control;
    
    _server.handleClientCommand(message.nPlayer, control);
}

void UdpGameMessageHandler::handleRegister(GameUdpMessage<MessageType> &message)
{
    _server.handleRegister(message.nPlayer);
}