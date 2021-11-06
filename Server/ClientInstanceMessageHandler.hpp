/*
** EPITECH PROJECT, 2021
** B-CPP-500-PAR-5-1-babel-alan.sigal
** File description:
** ClientInstanceMessageHandler
*/

#ifndef CLIENTINSTANCEMESSAGEHANDLER_HPP_
#define CLIENTINSTANCEMESSAGEHANDLER_HPP_

#include <map>
#include <list>
#include <memory>
#include "ClientInstanceMessage.hpp"
#include "network.hpp"
#include <initializer_list>
#include <asio.hpp>

class ClientInstanceMessageHandler;

typedef void (ClientInstanceMessageHandler::*MFP)(ClientInstanceMessage<MessageType> &);

class AsioServer;

class ClientInstanceMessageHandler {
    public:
        ClientInstanceMessageHandler(std::list<std::shared_ptr<ClientInstance>> &clientsConnected,
        AsioServer &server);
        ~ClientInstanceMessageHandler();
        void handleMessage(ClientInstanceMessage<MessageType> &message);
    private:
        void handleCreateGame(ClientInstanceMessage<MessageType> &message);
        void handleJoinGame(ClientInstanceMessage<MessageType> &message);
    private:
        std::list<std::shared_ptr<ClientInstance>> &_clientsConnected;
        std::map<MessageType, MFP> _map;
        AsioServer &_server;
};

#endif /* !CLIENTINSTANCEMESSAGEHANDLER_HPP_ */
