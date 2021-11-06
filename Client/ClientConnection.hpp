/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** ClientConnection
*/

#ifndef CLIENTCONNECTION_HPP_
#define CLIENTCONNECTION_HPP_

#include <asio.hpp>
#include "Message.hpp"
#include "network.hpp"
#include "INetwork.hpp"

class ClientConnection : public INetwork {
    public:
        ClientConnection(asio::ip::tcp::socket socket, asio::io_context &context);
        ~ClientConnection();
        bool isConnected();
        void connectToServer(const asio::ip::tcp::resolver::results_type& endpoints);
        void sendMessage(Message<MessageType> &message);
    protected:
        void writeMessageHeader(Message<MessageType> &message) override;
        void writeMessageBody(Message<MessageType> &message) override;
        void readMessageHeader() override;
        void readMessageBody() override;
    private:
        asio::ip::tcp::socket _socket;
        asio::io_context &_asioContext;
        Message<MessageType> _messageToWrite;
};

#endif /* !CLIENTCONNECTION_HPP_ */
