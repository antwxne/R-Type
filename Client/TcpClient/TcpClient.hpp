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
        void run();

        void sendMessage(Message<MessageType> &message);
        bool tryConnect(const std::string &ip, int port);

        std::string getIp() const;
        
        
        bool isConnected();
    private:
        void update();
    private:
        int _port;
        std::string _ip;

        asio::io_context _asioContext;
		std::thread _threadContext;
        std::shared_ptr<TcpClientConnection> _connection;
        std::list<Message<MessageType>> _messageList;
        TcpClientMessageHandler _messageHandler;
};

#endif /* !CLIENT_HPP_ */