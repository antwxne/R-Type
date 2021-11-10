/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** UdpGameMessageHandler
*/

#include "UdpGameMessageHandler.hpp"

typedef void (UdpGameMessageHandler::*MFP)(GameUdpMessage<MessageType> &);

UdpGameMessageHandler::UdpGameMessageHandler()
{
    _map[MessageType::GameCommand] = &UdpGameMessageHandler::handleCommand;
}

UdpGameMessageHandler::~UdpGameMessageHandler()
{
}

void UdpGameMessageHandler::handleMessage(GameUdpMessage<MessageType> &message)
{
    MFP fp;
    MessageType messageType = message.message.getMessageType();

    if (_map.find(messageType) == _map.end())
        return;

    fp = _map[messageType];

    return (this->*fp)(message);
}

void UdpGameMessageHandler::handleCommand(GameUdpMessage<MessageType> &message)
{
    std::cout << "Command!\n";
}