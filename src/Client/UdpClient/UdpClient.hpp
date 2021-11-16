/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** UdpClient
*/

#ifndef UDPCLIENT_HPP_
#define UDPCLIENT_HPP_


#include <asio.hpp>
#include <list>

#include "INetwork.hpp"
#include "network.hpp"
#include "UdpClientMessageHandler.hpp"


class UdpClient : public INetwork {
    public:
        UdpClient(const std::string &ip, int port);
        ~UdpClient();
        virtual void start();
        void run();

        void sendMessage(Message<MessageType> &message) override;
        void readMessageHeader() override;
        void readMessageBody(Message<MessageType> &message) override;
        void writeMessageHeader(Message<MessageType> &message) override;
        void writeMessageBody(Message<MessageType> &message) override;

    protected:
    protected:
        asio::io_context _asioContext;
        asio::ip::udp::socket _socket;
        asio::ip::udp::endpoint _serverEndpoint;
        std::thread _threadContext;

        std::list<Message<MessageType>> _messageList;
        UdpClientMessageHandler _messageHandler;
};

#endif /* !UDPCLIENT_HPP_ */
