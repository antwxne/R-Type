/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** UdpAsioServer
*/

#include "UdpAsioServer.hpp"
#include <functional>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

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
        sleep(0.1);
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
    _socket.async_receive_from(asio::buffer(_tmpMessage.getHeaderPtr(), _tmpMessage.getHeaderSize()),
    _lastEndpoint, boost::bind(&UdpAsioServer::handleHeaderRecieve, this, boost::asio::placeholders::error,
    boost::asio::placeholders::bytes_transferred));
}

void UdpAsioServer::handleHeaderRecieve(const asio::error_code& error, std::size_t size)
{
    if (error)
    {
        readMessageHeader();
        return;
    }
    if (_tmpMessage.getBodySize() > 0)
    {
        _tmpMessage.resizeBody(_tmpMessage.getBodySize());
        readMessageBody();
    }
    else
    {
        _messageList.push_back(_tmpMessage);
        readMessageHeader();
    }
}

void UdpAsioServer::readMessageBody()
{
    _socket.async_receive_from(asio::buffer(_tmpMessage.getBodyDataPtr(), _tmpMessage.getBodySize()),
    _lastEndpoint, boost::bind(&UdpAsioServer::handleHeaderRecieve, this, boost::asio::placeholders::error,
    boost::asio::placeholders::bytes_transferred));
}

void UdpAsioServer::handleBodyRecieve(const asio::error_code& error, std::size_t size)
{
    if (error)
    {
        readMessageHeader();
        return;
    }
    _messageList.push_back(_tmpMessage);
    readMessageHeader();
}

void UdpAsioServer::writeMessageHeader(Message<MessageType> &message)
{

}

void UdpAsioServer::writeMessageBody(Message<MessageType> &message)
{

}

void UdpAsioServer::writeMessageHeaderToEndpoint(Message<MessageType> &message, asio::ip::udp::endpoint &clientEndpoint)
{
    _socket.send_to(asio::buffer(message.getHeaderPtr(), message.getHeaderSize()), clientEndpoint);
    if (message.getBodySize() > 0)
        writeMessageBodyToEndpoint(message, clientEndpoint);
}

void UdpAsioServer::writeMessageBodyToEndpoint(Message<MessageType> &message, asio::ip::udp::endpoint &clientEndpoint)
{
    _socket.send_to(asio::buffer(message.getBodyDataPtr(), message.getBodySize()), clientEndpoint);
}