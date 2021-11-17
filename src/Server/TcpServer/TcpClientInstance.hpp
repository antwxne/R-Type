/*
** EPITECH PROJECT, 2021
** B-CPP-500-PAR-5-1-babel-alan.sigal
** File description:
** TcpClientInstance
*/

#ifndef TcpClientInstance_HPP_
#define TcpClientInstance_HPP_

#include <asio.hpp>
#include "Message.hpp"
#include "network.hpp"
#include "INetwork.hpp"
#include <list>
#include <vector>
#include "TcpClientInstanceMessage.hpp"
#include "../ClientInformations.hpp"

template<typename T>
class TcpClientInstanceMessage;

class TcpClientInstance : public std::enable_shared_from_this<TcpClientInstance>, public INetwork{
    public:
        TcpClientInstance(asio::io_context& asioContext, asio::ip::tcp::socket socket, std::list<TcpClientInstanceMessage<MessageType>> &_messageList);
        ~TcpClientInstance();
        void sendMessage(Message<MessageType> &message) override;
        void readMessageHeader() override;
        bool isConnected();
        asio::ip::tcp::endpoint getSocketEndpoint();
    private:
        void writeMessageHeader(Message<MessageType> &message) override;
        void readMessageBody(Message<MessageType> &message) override;
        void writeMessageBody(Message<MessageType> &message) override;
    public:
        ClientInformations informations;
    private:
        asio::io_context& _asioContext;
        asio::ip::tcp::socket _socket;
        bool _isConnected;
        std::list<TcpClientInstanceMessage<MessageType>> &_messageList;
        Message<MessageType> _messageToRead;
};

#endif /* !TcpClientInstance_HPP_ */
