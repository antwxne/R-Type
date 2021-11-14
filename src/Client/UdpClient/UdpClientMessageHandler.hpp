/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** UdpClientMessageHandler
*/

#ifndef UDPCLIENTMESSAGEHANDLER_HPP_
#define UDPCLIENTMESSAGEHANDLER_HPP_

#include "Message.hpp"
#include "network.hpp"
#include <map>

class UdpClientMessageHandler;

typedef void (UdpClientMessageHandler::*UdpMFP)(Message<MessageType> &);

class UdpClientMessageHandler {
    public:
        UdpClientMessageHandler();
        ~UdpClientMessageHandler();
        void handleMessage(Message<MessageType> &message);
    private:

    protected:
    private:
        std::map<MessageType, UdpMFP> _map;
};

#endif /* !UDPCLIENTMESSAGEHANDLER_HPP_ */
