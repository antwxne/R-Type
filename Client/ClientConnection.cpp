/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** ClientConnection
*/

#include "ClientConnection.hpp"

ClientConnection::ClientConnection(asio::ip::tcp::socket socket, asio::io_context &context)
: _socket(std::move(socket)), _asioContext(context)
{
}

ClientConnection::~ClientConnection()
{
}

bool ClientConnection::isConnected()
{
    return _socket.is_open();
}

void ClientConnection::connectToServer(const asio::ip::tcp::resolver::results_type& endpoints)
{
    _socket = asio::ip::tcp::socket(_asioContext);

    asio::async_connect(_socket, endpoints,
	[this](std::error_code ec, asio::ip::tcp::endpoint endpoint)
	{
	    if (!ec)
		{
            std::cout << "Connected to " << endpoint << std::endl;
		}
	});
}

void ClientConnection::sendMessage(Message<MessageType> &message)
{
    writeMessageHeader(message);
}

void ClientConnection::writeMessageHeader(Message<MessageType> &message)
{
    _messageToWrite = message;
    asio::async_write(_socket, asio::buffer(_messageToWrite.getHeaderPtr(), _messageToWrite.getHeaderSize()),
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
        }
    });
}

void ClientConnection::writeMessageBody(Message<MessageType> &message)
{
    asio::async_write(_socket, asio::buffer(message.getBodyDataPtr(), message.getBodySize()),
	[this](std::error_code ec, std::size_t length)
    {
        if (ec)
        {
            _socket.close();
        }
        else
        {
            std::cout << length << std::endl;
        }
        
    });
}

void ClientConnection::readMessageHeader()
{

}

void ClientConnection::readMessageBody()
{

}
