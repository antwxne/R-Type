/*
** EPITECH PROJECT, 2021
** B-CPP-500-PAR-5-1-babel-alan.sigal
** File description:
** ClientInstanceMessageHandler
*/

#include "ClientInstanceMessageHandler.hpp"
#include "ClientInstance.hpp"
#include <iostream>

typedef void (ClientInstanceMessageHandler::*MFP)(ClientInstanceMessage<MessageType> &);

ClientInstanceMessageHandler::ClientInstanceMessageHandler(std::list<std::shared_ptr<ClientInstance>> &clientsConnected)
    : _clientsConnected(clientsConnected)
{
    
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