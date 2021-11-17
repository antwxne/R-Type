/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** TcpClientConnection
*/

#include "TcpClientConnection.hpp"

TcpClientConnection::TcpClientConnection(asio::ip::tcp::socket socket, asio::io_context &context,
std::list<Message<MessageType>> &messageList)
: _socket(std::move(socket)), _asioContext(context), _messageList(messageList)
{
    _isConnected = false;
}

TcpClientConnection::~TcpClientConnection()
{
}

bool TcpClientConnection::isConnected()
{
    return _socket.is_open() && _isConnected;
}

std::string TcpClientConnection::getIp() const
{
    return _socket.local_endpoint().address().to_string();
}

void TcpClientConnection::connectToServer(const asio::ip::tcp::resolver::results_type& endpoints)
{
    _socket = asio::ip::tcp::socket(_asioContext);

    asio::async_connect(_socket, endpoints,
	[this](std::error_code ec, asio::ip::tcp::endpoint endpoint)
	{
	    if (!ec)
		{
            std::cout << "Connected to " << endpoint << std::endl;
            readMessageHeader();
            _isConnected = true;
		}
        else
        {
            std::cout << "Cannot connect: " << ec << std::endl;
        }
	});
}

void TcpClientConnection::sendMessage(Message<MessageType> &message)
{
    writeMessageHeader(message);
}

void TcpClientConnection::writeMessageHeader(Message<MessageType> &message)
{
    asio::async_write(_socket, asio::buffer(message.getHeaderPtr(), message.getHeaderSize()),
	[this, message](std::error_code ec, std::size_t length) mutable 
    {
        if (!ec)
        {
            if (message.getBodySize() > 0)
            {
                writeMessageBody(message);
                return;
            }
        }
        else
        {
            _socket.close();
        }
    });
}

void TcpClientConnection::writeMessageBody(Message<MessageType> &message)
{
    asio::async_write(_socket, asio::buffer(message.getBodyDataPtr(), message.getBodySize()),
	[this](std::error_code ec, std::size_t length)
    {
        if (ec)
        {
            _socket.close();
        }
    });
}

void TcpClientConnection::readMessageHeader()
{
    _tmpMessage = Message<MessageType>();
    asio::async_read(_socket, asio::buffer(_tmpMessage.getHeaderPtr(), _tmpMessage.getHeaderSize()),
	[this](std::error_code ec, std::size_t length) mutable
    {
        if (!ec)
        {
            if (_tmpMessage.getBodySize() > 0)
            {
                _tmpMessage.resizeBody(_tmpMessage.getBodySize());
                readMessageBody(_tmpMessage);
            }
            else
            {
                _messageList.push_back(_tmpMessage);
                readMessageHeader();
            }
        }
        else
        {
            _socket.close();
        }
    });
}


void TcpClientConnection::readMessageBody(Message<MessageType> &message)
{
    asio::async_read(_socket, asio::buffer(_tmpMessage.getBodyDataPtr(), _tmpMessage.getBodySize()),
	[this, message](std::error_code ec, std::size_t length) mutable
    {
        if (ec)
        {
            _socket.close();
        }
        else
        {
            _messageList.push_back(_tmpMessage);
            readMessageHeader();
        }
    });
}