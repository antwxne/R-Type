/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** UdpGameClientMessageHandler
*/

#include "UdpGameClientMessageHandler.hpp"
#include "UdpGameClient.hpp"
#include "NetworkEntityInformation.hpp"

typedef void (UdpGameClientMessageHandler::*UdpGameMFP)(Message<MessageType> &);

UdpGameClientMessageHandler::UdpGameClientMessageHandler(UdpGameClient &client) : _client(client)
{
    _map[MessageType::EnemyEntityUpdate] = &UdpGameClientMessageHandler::handleEnnemyUpdate;
}

UdpGameClientMessageHandler::~UdpGameClientMessageHandler()
{
}

void UdpGameClientMessageHandler::handleMessage(Message<MessageType> &message)
{
    UdpGameMFP fp;
    MessageType messageType = message.getMessageType();

    if (_map.find(messageType) == _map.end())
        return;

    fp = _map[messageType];

    return (this->*fp)(message);
}

void UdpGameClientMessageHandler::handleEnnemyUpdate(Message<MessageType> &message)
{
    NetworkEntityInformation info;

    message >> info;

    std::cout << "New info pos = " << info.position.y << std::endl;
    _client.addEntityInfo(info);
}