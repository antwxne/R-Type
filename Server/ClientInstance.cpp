/*
** EPITECH PROJECT, 2021
** B-CPP-500-PAR-5-1-babel-alan.sigal
** File description:
** ClientInstance
*/

#include "ClientInstance.hpp"
#include <iostream>

ClientInstance::ClientInstance(asio::io_context& asioContext, asio::ip::tcp::socket socket, std::list<ClientInstanceMessage<MessageType>> &messageList)
: _asioContext(asioContext), _socket(std::move(socket)), _messageList(messageList)
{
    _isConnected = true;
}

ClientInstance::~ClientInstance()
{
}


void ClientInstance::readMessageHeader()
{
    asio::async_read(_socket, asio::buffer(_tmpMessage.getHeaderPtr(), _tmpMessage.getHeaderSize()),
	[this](std::error_code ec, std::size_t length)
    {
        if (!ec)
        {
            if (_tmpMessage.getBodySize() > 0)
            {
                _tmpMessage.resizeBody(_tmpMessage.getBodySize());
                readMessageBody();
            }
            else
            {
                _messageList.push_back(ClientInstanceMessage<MessageType>(_tmpMessage, this->shared_from_this()));
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


void ClientInstance::readMessageBody()
{
    asio::async_read(_socket, asio::buffer(_tmpMessage.getBodyDataPtr(), _tmpMessage.getBodySize()),
		[this](std::error_code ec, std::size_t length)
    {
        if (ec)
        {
            _socket.close();
            _isConnected = false;
        }
        else
        {
            _messageList.push_back(ClientInstanceMessage<MessageType>(_tmpMessage, this->shared_from_this()));
            readMessageHeader();
        }
    });
}

void ClientInstance::writeMessageHeader(Message<MessageType> &message)
{
    _messageToWrite = message;
    asio::async_write(_socket, asio::buffer(message.getHeaderPtr(),  message.getHeaderSize()),
	[this](std::error_code ec, std::size_t length)
    {
        if (!ec)
        {
            if (_messageToWrite.getBodySize() > 0)
                writeMessageBody(_messageToWrite);
        }
        else
        {
            _socket.close();
            _isConnected = false;
        }
    });
}

void ClientInstance::writeMessageBody(Message<MessageType> &message)
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


bool ClientInstance::isConnected()
{
    return _isConnected;
}

asio::ip::tcp::endpoint ClientInstance::getSocketEndpoint()
{
    return _socket.remote_endpoint();
}