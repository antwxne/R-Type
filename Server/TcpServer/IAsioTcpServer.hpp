/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** IAsioTcpServer
*/

#ifndef IASIOTCPSERVER_HPP_
#define IASIOTCPSERVER_HPP_

#include "ITcpServer.hpp"
#include <asio.hpp>
#include "../ClientInstance.hpp"
#include <memory>

class IAsioTcpServer : public ITcpServer {
    public:
        virtual void onClientConnected(asio::ip::tcp::socket &socket) = 0;
        virtual void onClientDisconnected(std::shared_ptr<ClientInstance> &client) = 0;
};

#endif /* !IASIOTCPSERVER_HPP_ */
