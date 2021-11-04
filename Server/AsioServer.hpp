/*
** EPITECH PROJECT, 2021
** B-CPP-500-PAR-5-1-babel-alan.sigal
** File description:
** AsioServer
*/

#ifndef ASIOSERVER_HPP_
#define ASIOSERVER_HPP_

#include "../Network/INetwork.hpp"
#include <asio.hpp>
#include <thread>
#include <list>
#include <memory>
#include <iostream>
#include "ClientInstance.hpp"
#include "ClientInstanceMessage.hpp"
#include "ClientInstanceMessageHandler.hpp"

class AsioServer {
    public:
        AsioServer(int port);
        ~AsioServer();
        void start();
        void stop();
        void update();
    private:
        void acceptClientsConnection();
    private:
        int _port;
        asio::io_context _asioContext;
		std::thread _threadContext;
        asio::ip::tcp::acceptor _asioAcceptor;
        std::list<std::shared_ptr<ClientInstance>> _clientsConnected;
        std::list<ClientInstanceMessage<MessageType>> _messageList; // TODO change to safe queue
        ClientInstanceMessageHandler _messageHandler;
};

#endif /* !ASIOSERVER_HPP_ */
