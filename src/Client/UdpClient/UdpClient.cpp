/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** UdpClient
*/

#include "UdpClient.hpp"
#include "network.hpp"
#include "Message.hpp"

UdpClient::UdpClient(const std::string &ip, int port) :
_socket(_asioContext)
{
    _socket.open(asio::ip::udp::v4());
    _serverEndpoint = asio::ip::udp::endpoint(asio::ip::address::from_string(ip), port);
}

UdpClient::~UdpClient()
{
}



void UdpClient::start()
{
    readMessageHeader();
    _threadContext = std::thread([this]() { _asioContext.run(); });
    run();
}

void UdpClient::run()
{
    while (1)
    {
        if (_messageList.size() > 0)
        {
            Message<MessageType> message = _messageList.front();
            _messageList.pop_front();
            _messageHandler.handleMessage(message);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void UdpClient::sendMessage(Message<MessageType> &message)
{
    writeMessageHeader(message);
}

void UdpClient::readMessageHeader()
{
    Message<MessageType> message;
    _socket.async_receive_from(asio::buffer(message.getHeaderPtr(), message.getHeaderSize()), _serverEndpoint,
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


void UdpClient::readMessageBody(Message<MessageType> &message)
{
    _socket.async_receive_from(asio::buffer(message.getBodyDataPtr(), message.getBodySize()), _serverEndpoint,
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

void UdpClient::writeMessageHeader(Message<MessageType> &message)
{
    _socket.async_send_to(asio::buffer(message.getHeaderPtr(), message.getHeaderSize()), _serverEndpoint,
    [this, message](std::error_code ec, std::size_t length) mutable
    {
        if (ec)
        {
            return;
        }
        if (message.getBodySize() > 0)
            writeMessageBody(message);
    });
}

void UdpClient::writeMessageBody(Message<MessageType> &message)
{
    _socket.async_send_to(asio::buffer(message.getBodyDataPtr(), message.getBodySize()), _serverEndpoint,
    [this, message](std::error_code ec, std::size_t length) mutable
    {
        if (ec)
        {
            return;
        }
    });
}