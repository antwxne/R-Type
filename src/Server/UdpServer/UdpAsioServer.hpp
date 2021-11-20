/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** UdpAsioServer
*/

#ifndef UDPASIOSERVER_HPP_
#define UDPASIOSERVER_HPP_

#include <thread>
#include <asio.hpp>
#include <list>

#include "Message.hpp"
#include "network.hpp"
#include "INetwork.hpp"

class UdpAsioServer : public INetwork {
    public:
        UdpAsioServer(int port = 0);
        ~UdpAsioServer();
        void start();
        virtual void stop();
        virtual void run();
        int getPort();


        void readMessageHeader() override;
        void readMessageBody() override;

        void sendMessage(Message<MessageType> &message) override;
        void writeMessageHeader(Message<MessageType> &message) override;
        void writeMessageBody(Message<MessageType> &message) override;

        void writeMessageHeaderToEndpoint(Message<MessageType> &message, const asio::ip::udp::endpoint &clientEndpoint);
        void writeMessageBodyToEndpoint(Message<MessageType> &message, const asio::ip::udp::endpoint &clientEndpoint);

    protected:
        asio::io_context _asioContext;
		std::thread _threadContext;
        asio::ip::udp::socket _socket;
        asio::ip::udp::endpoint _lastEndpoint;
        bool _running;

        Message<MessageType> _tmpMessage;

        std::list<Message<MessageType>> _messageList;

};

#endif /* !UDPASIOSERVER_HPP_ */
