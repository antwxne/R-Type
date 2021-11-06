/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <asio.hpp>
#include "Message.hpp"
#include "network.hpp"
#include "ClientConnection.hpp"

class Client
{
    public:
        Client();
        ~Client();
        void start();
        void run();
        bool tryConnect(const std::string &ip, int port);
        void createGame(const std::string &name);
        void joinGame(const std::string &name);
        void sendMessage(Message<MessageType> &message);
        bool isConnected();
    private:
        asio::io_context _asioContext;
		std::thread _threadContext;
        std::unique_ptr<ClientConnection> _connection;
};

#endif /* !CLIENT_HPP_ */
