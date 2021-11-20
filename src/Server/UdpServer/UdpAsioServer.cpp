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
    _running = true;
}

UdpAsioServer::~UdpAsioServer()
{
}

void UdpAsioServer::stop()
{
    _running = false;
    _asioContext.stop();
    _threadContext.join();
}

void UdpAsioServer::start()
{
    readMessageHeader();
    _threadContext = std::thread([this]() { _asioContext.run(); });
}

void UdpAsioServer::run()
{
    while (_running)
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
   _tmpMessage = Message<MessageType>();

    _socket.async_receive_from(asio::buffer(_tmpMessage.getHeaderPtr(), _tmpMessage.getHeaderSize()), _lastEndpoint,
    [this](std::error_code ec, std::size_t length)
    {
        if (ec)
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
    });
}

void UdpAsioServer::readMessageBody()
{
    _socket.async_receive_from(asio::buffer(_tmpMessage.getBodyDataPtr(), _tmpMessage.getBodySize()), _lastEndpoint,
    [this](std::error_code ec, std::size_t length)
    {
        if (ec)
        {
            readMessageHeader();
            return;
        }
        _messageList.push_back(_tmpMessage);
        readMessageHeader();
    });
}

void UdpAsioServer::writeMessageHeader(Message<MessageType> &message)
{

}

void UdpAsioServer::writeMessageBody(Message<MessageType> &message)
{

}

void UdpAsioServer::writeMessageHeaderToEndpoint(Message<MessageType> &message, const asio::ip::udp::endpoint &clientEndpoint)
{
    _socket.send_to(asio::buffer(message.getHeaderPtr(), message.getHeaderSize()), clientEndpoint);

    if (message.getBodySize() > 0)
        writeMessageBodyToEndpoint(message, clientEndpoint);
    
}

void UdpAsioServer::writeMessageBodyToEndpoint(Message<MessageType> &message, const asio::ip::udp::endpoint &clientEndpoint)
{
    _socket.send_to(asio::buffer(message.getBodyDataPtr(), message.getBodySize()), clientEndpoint);
}