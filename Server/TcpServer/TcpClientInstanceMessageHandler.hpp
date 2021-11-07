/*
** EPITECH PROJECT, 2021
** B-CPP-500-PAR-5-1-babel-alan.sigal
** File description:
** TcpClientInstanceMessageHandler
*/

#ifndef TcpClientInstanceMessageHandler_HPP_
#define TcpClientInstanceMessageHandler_HPP_

#include <map>
#include <list>
#include <memory>
#include "TcpClientInstanceMessage.hpp"
#include "network.hpp"
#include <initializer_list>
#include <asio.hpp>

class TcpClientInstanceMessageHandler;

typedef void (TcpClientInstanceMessageHandler::*MFP)(TcpClientInstanceMessage<MessageType> &);

class AsioServer;

class TcpClientInstanceMessageHandler
{
    public:
        TcpClientInstanceMessageHandler(std::list<std::shared_ptr<TcpClientInstance>> &clientsConnected,
        AsioServer &server);
        ~TcpClientInstanceMessageHandler();
        void handleMessage(TcpClientInstanceMessage<MessageType> &message);
    private:
        void writeResponse(TcpClientInstanceMessage<MessageType> &inMessage, int responseCode);
        void handleCreateGame(TcpClientInstanceMessage<MessageType> &message);
        void handleJoinGame(TcpClientInstanceMessage<MessageType> &message);
    private:
        std::list<std::shared_ptr<TcpClientInstance>> &_clientsConnected;
        std::map<MessageType, MFP> _map;
        AsioServer &_server;
};

#endif /* !TcpClientInstanceMessageHandler_HPP_ */
