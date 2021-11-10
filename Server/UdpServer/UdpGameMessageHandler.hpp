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

typedef void (UdpGameMessageHandler::*MFP)(GameUdpMessage<MessageType> &);

class UdpGameMessageHandler {
    public:
        UdpGameMessageHandler();
        ~UdpGameMessageHandler();
        void handleMessage(GameUdpMessage<MessageType> &message);
    private:
        void handleCommand(GameUdpMessage<MessageType> &message);

    protected:
    private:
        std::map<MessageType, MFP> _map;
};

#endif /* !UDPGAMEMESSAGEHANDLER_HPP_ */
