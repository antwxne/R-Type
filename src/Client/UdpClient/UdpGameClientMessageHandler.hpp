/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** UdpGameClientMessageHandler
*/

#ifndef UDPGAMECLIENTMESSAGEHANDLER_HPP_
#define UDPGAMECLIENTMESSAGEHANDLER_HPP_

#include "Message.hpp"
#include "network.hpp"
#include <map>

class UdpGameClientMessageHandler;

typedef void (UdpGameClientMessageHandler::*UdpGameMFP)(Message<MessageType> &);

class UdpGameClient;

class UdpGameClientMessageHandler
{
    public:
        UdpGameClientMessageHandler(UdpGameClient &client);
        ~UdpGameClientMessageHandler();
        void handleMessage(Message<MessageType> &message);
        
    protected:
        void handleEntityUpdate(Message<MessageType> &message);
    private:
        UdpGameClient &_client;
        std::map<MessageType, UdpGameMFP> _map;
};

#endif /* !UDPGAMECLIENTMESSAGEHANDLER_HPP_ */
