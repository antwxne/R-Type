/*
** EPITECH PROJECT, 2021
** B-CPP-500-PAR-5-1-babel-alan.sigal
** File description:
** AsioServer
*/

#ifndef ASIOSERVER_HPP_
#define ASIOSERVER_HPP_

#include "INetwork.hpp"
#include "IAsioTcpServer.hpp"
#include <asio.hpp>
#include <thread>
#include <list>
#include <memory>
#include <iostream>
#include "TcpClientInstance.hpp"
#include "TcpClientInstanceMessage.hpp"
#include "TcpClientInstanceMessageHandler.hpp"
#include "../GameInstance/GameInstancesHandler.hpp"

//class TcpClientInstanceMessageHandler;

class AsioServer : public IAsioTcpServer {
    public:
        AsioServer(int port);
        ~AsioServer();
        void start() override;
        void stop() override;
        void update() override;
        void run() override;
    private:
        void acceptClientsConnection() override;
        void onClientConnected(asio::ip::tcp::socket &socket) override;
        void onClientDisconnected(std::shared_ptr<TcpClientInstance> &client) override;
    public:
        GameInstancesHandler gamesHandler;
    private:
        int _port;
        asio::io_context _asioContext;
		std::thread _threadContext;
        asio::ip::tcp::acceptor _asioAcceptor;
        std::list<std::shared_ptr<TcpClientInstance>> _clientsConnected;
        std::list<TcpClientInstanceMessage<MessageType>> _messageList;
        TcpClientInstanceMessageHandler _messageHandler;
};

#endif /* !ASIOSERVER_HPP_ */
