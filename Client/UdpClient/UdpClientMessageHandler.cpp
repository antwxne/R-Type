/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** UdpClientMessageHandler
*/

#include "UdpClientMessageHandler.hpp"

UdpClientMessageHandler::UdpClientMessageHandler()
{
}

UdpClientMessageHandler::~UdpClientMessageHandler()
{
}

void UdpClientMessageHandler::handleMessage(Message<MessageType> &message)
{
    MFP fp;
    MessageType messageType = message.getMessageType();

    if (_map.find(messageType) == _map.end())
        return;

    fp = _map[messageType];

    return (this->*fp)(message);
}