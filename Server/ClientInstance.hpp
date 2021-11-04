/*
** EPITECH PROJECT, 2021
** B-CPP-500-PAR-5-1-babel-alan.sigal
** File description:
** ClientInstance
*/

#ifndef CLIENTINSTANCE_HPP_
#define CLIENTINSTANCE_HPP_

#include <asio.hpp>
#include "../Network/Message.hpp"
#include "../Network/network.hpp"
#include "../Network/INetwork.hpp"
#include <list>
#include "ClientInstanceMessage.hpp"


class ClientInstance : public std::enable_shared_from_this<ClientInstance>, public INetwork{
    public:
        ClientInstance(asio::io_context& _asioContext, asio::ip::tcp::socket socket, std::list<ClientInstanceMessage<MessageType>> &_messageList);
        ~ClientInstance();
        void readMessageHeader() override;
        void writeMessageHeader(Message<MessageType> &message) override;
        bool isConnected();
        asio::ip::tcp::endpoint getSocketEndpoint();
    private:
        void readMessageBody() override;
        void writeMessageBody(Message<MessageType> &message) override;
    private:
        asio::io_context& _asioContext;
        asio::ip::tcp::socket _socket;
        Message<MessageType> _tmpMessage;
        Message<MessageType> _messageToWrite;
        bool _isConnected;
        std::list<ClientInstanceMessage<MessageType>> &_messageList;
};

#endif /* !CLIENTINSTANCE_HPP_ */
