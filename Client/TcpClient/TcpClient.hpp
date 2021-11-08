/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Client
*/

#ifndef TCPCLIENT_HPP_
#define TCPCLIENT_HPP_

#include <asio.hpp>
#include <list>

#include "Message.hpp"
#include "network.hpp"
#include "TcpClientConnection.hpp"
#include "TcpClientMessageHandler.hpp"

class TcpClient
{
    public:
        TcpClient();
        ~TcpClient();
        void start();
        bool tryConnect(const std::string &ip, int port);
        void createGame(const std::string &name);
        void joinGame(const std::string &name);
        void leaveGame(const std::string &name);
        bool isConnected();
    private:
        void run();
        void update();
        void sendMessage(Message<MessageType> &message);
    private:
        asio::io_context _asioContext;
		std::thread _threadContext;
        std::unique_ptr<TcpClientConnection> _connection;
        std::list<Message<MessageType>> _messageList;
        TcpClientMessageHandler _messageHandler;
};

#endif /* !CLIENT_HPP_ */
