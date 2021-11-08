/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** TcpClientMessageHandler
*/

#ifndef TCPCLIENTMESSAGEHANDLER_HPP_
#define TCPCLIENTMESSAGEHANDLER_HPP_

#include <map>
#include "Message.hpp"
#include "network.hpp"

class TcpClientMessageHandler;
class TcpClient;

typedef void (TcpClientMessageHandler::*MFP)(Message<MessageType> &);

class TcpClientMessageHandler {
    public:
        TcpClientMessageHandler(TcpClient &client);
        ~TcpClientMessageHandler();
        void handleMessage(Message<MessageType> &message);
    private:
        void handleCreateGame(Message<MessageType> &message);
        void handleJoinGame(Message<MessageType> &message);
        void handleLeaveGame(Message<MessageType> &message);
    private:
        std::map<MessageType, MFP> _map;
        TcpClient &_client;
};

#endif /* !TCPCLIENTMESSAGEHANDLER_HPP_ */
