/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** TcpClientConnection
*/

#ifndef TcpClientConnection_HPP_
#define TcpClientConnection_HPP_

#include <asio.hpp>
#include <list>
#include "Message.hpp"
#include "network.hpp"
#include "INetwork.hpp"

class TcpClientConnection : public INetwork {
    public:
        TcpClientConnection(asio::ip::tcp::socket socket, asio::io_context &context,
        std::list<Message<MessageType>> &messageList);
        ~TcpClientConnection();
        bool isConnected();
        void connectToServer(const asio::ip::tcp::resolver::results_type& endpoints);
        void sendMessage(Message<MessageType> &message) override;
    protected:
        void writeMessageHeader(Message<MessageType> &message) override;
        void writeMessageBody(Message<MessageType> &message) override;
        void readMessageHeader() override;
        void readMessageBody() override;
    private:
        asio::ip::tcp::socket _socket;
        asio::io_context &_asioContext;
        Message<MessageType> _tmpMessage;
        Message<MessageType> _messageToWrite;
        std::list<Message<MessageType>> &_messageList;
};

#endif /* !TcpClientConnection_HPP_ */
