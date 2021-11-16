/*
** EPITECH PROJECT, 2021
** B-CPP-500-PAR-5-1-babel-alan.sigal
** File description:
** TcpClientInstance
*/

#include "TcpClientInstance.hpp"
#include <iostream>

TcpClientInstance::TcpClientInstance(asio::io_context& asioContext, asio::ip::tcp::socket socket, std::list<TcpClientInstanceMessage<MessageType>> &messageList)
: _asioContext(asioContext), _socket(std::move(socket)), _messageList(messageList)
{
    _isConnected = true;
}

TcpClientInstance::~TcpClientInstance()
{
}

void TcpClientInstance::sendMessage(Message<MessageType> &message)
{
    writeMessageHeader(message);
}

void TcpClientInstance::readMessageHeader()
{
    _messageToRead = Message<MessageType>();

    asio::async_read(_socket, asio::buffer(_messageToRead.getHeaderPtr(), _messageToRead.getHeaderSize()),
	[this](std::error_code ec, std::size_t length)
    {
        if (!ec)
        {
            if (_messageToRead.getBodySize() > 0)
            {
                _messageToRead.resizeBody(_messageToRead.getBodySize());
                readMessageBody(_messageToRead);
            }
            else
            {
                _messageList.push_back(TcpClientInstanceMessage<MessageType>(_messageToRead, this->shared_from_this()));
                readMessageHeader();
            }
        }
        else
        {
            _socket.close();
            _isConnected = false;
        }
    });
}

void TcpClientInstance::readMessageBody(Message<MessageType> &message)
{
    asio::async_read(_socket, asio::buffer(_messageToRead.getBodyDataPtr(), _messageToRead.getBodySize()),
	[this, message](std::error_code ec, std::size_t length) mutable
    {
        if (ec)
        {
            _socket.close();
            _isConnected = false;
        }
        else
        {
            _messageList.push_back(TcpClientInstanceMessage<MessageType>(_messageToRead, this->shared_from_this()));
            readMessageHeader();
        }
    });
}

void TcpClientInstance::writeMessageHeader(Message<MessageType> &message)
{
    asio::async_write(_socket, asio::buffer(message.getHeaderPtr(),  message.getHeaderSize()),
	[this, message](std::error_code ec, std::size_t length) mutable
    {
        if (!ec)
        {
            if (message.getBodySize() > 0)
                writeMessageBody(message);
        }
        else
        {
            _socket.close();
            _isConnected = false;
        }
    });
}

void TcpClientInstance::writeMessageBody(Message<MessageType> &message)
{
    asio::async_write(_socket, asio::buffer(message.getBodyDataPtr(), message.getBodySize()),
	[this](std::error_code ec, std::size_t length)
    {
        if (ec)
        {
            _socket.close();
            _isConnected = false;
        }        
    });
}


bool TcpClientInstance::isConnected()
{
    return _isConnected;
}

asio::ip::tcp::endpoint TcpClientInstance::getSocketEndpoint()
{
    return _socket.remote_endpoint();
}