/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** UdpGameMessageHandler
*/

#ifndef UDPGAMEMESSAGEHANDLER_HPP_
#define UDPGAMEMESSAGEHANDLER_HPP_

#include "GameUdpMessage.hpp"
#include "network.hpp"
#include <map>

class UdpGameMessageHandler;

typedef void (UdpGameMessageHandler::*UdpMFP)(GameUdpMessage<MessageType> &);

class GameUdpServer;

class UdpGameMessageHandler {
    public:
        UdpGameMessageHandler(GameUdpServer &server);
        ~UdpGameMessageHandler();
        void handleMessage(GameUdpMessage<MessageType> &message);
    private:
        void handleCommand(GameUdpMessage<MessageType> &message);
        void handleRegister(GameUdpMessage<MessageType> &message);

    protected:
    private:
        std::map<MessageType, UdpMFP> _map;
        GameUdpServer &_server;
};

#endif /* !UDPGAMEMESSAGEHANDLER_HPP_ */
