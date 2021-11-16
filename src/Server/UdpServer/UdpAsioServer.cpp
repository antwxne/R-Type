/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** UdpAsioServer
*/

#include "UdpAsioServer.hpp"
#include <functional>

UdpAsioServer::UdpAsioServer(int port) :
_socket(_asioContext, asio::ip::udp::endpoint(asio::ip::udp::v4(), port))
{
}

UdpAsioServer::~UdpAsioServer()
{
}

void UdpAsioServer::start()
{
    readMessageHeader();
    _threadContext = std::thread([this]() { _asioContext.run(); });
    run();
}

void UdpAsioServer::run()
{
    while (1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

int UdpAsioServer::getPort()
{
    return _socket.local_endpoint().port();
}

void UdpAsioServer::sendMessage(Message<MessageType> &message)
{
    writeMessageHeader(message);
}

void UdpAsioServer::readMessageHeader()
{
    Message<MessageType> message;

    _socket.async_receive_from(asio::buffer(message.getHeaderPtr(), message.getHeaderSize()), _lastEndpoint,
    [this, message](std::error_code ec, std::size_t length) mutable
    {
        if (ec)
        {
            readMessageHeader();
            return;
        }
        if (message.getBodySize() > 0)
        {
            message.resizeBody(message.getBodySize());
            readMessageBody(message);
        }
        else
        {
            _messageList.push_back(message);
            readMessageHeader();
        }
    });
}

void UdpAsioServer::readMessageBody(Message<MessageType> &message)
{
    _socket.async_receive_from(asio::buffer(message.getBodyDataPtr(), message.getBodySize()), _lastEndpoint,
    [this, message](std::error_code ec, std::size_t length) mutable
    {
        if (ec)
        {
            readMessageHeader();
            return;
        }
        _messageList.push_back(message);
        readMessageHeader();
    });
}

void UdpAsioServer::writeMessageHeader(Message<MessageType> &message)
{

}

void UdpAsioServer::writeMessageBody(Message<MessageType> &message)
{

}

void UdpAsioServer::writeMessageHeaderToEndpoint(Message<MessageType> &message, asio::ip::udp::endpoint &clientEndpoint)
{
    _socket.async_send_to(asio::buffer(message.getHeaderPtr(), message.getHeaderSize()), clientEndpoint, 
    [this, message, clientEndpoint](std::error_code ec, std::size_t length) mutable
    {
        if (ec)
        {
            return;
        }
        if (message.getBodySize() > 0)
            writeMessageBodyToEndpoint(message, clientEndpoint);
    });
    
}

void UdpAsioServer::writeMessageBodyToEndpoint(Message<MessageType> &message, asio::ip::udp::endpoint &clientEndpoint)
{
    _socket.async_send_to(asio::buffer(message.getBodyDataPtr(), message.getBodySize()), clientEndpoint,
    [this](std::error_code ec, std::size_t length) mutable
    {
        if (ec)
        {
            return;
        }
    });
}