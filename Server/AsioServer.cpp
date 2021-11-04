/*
** EPITECH PROJECT, 2021
** B-CPP-500-PAR-5-1-babel-alan.sigal
** File description:
** AsioServer
*/

#include "AsioServer.hpp"
#include <iostream>

AsioServer::AsioServer(int port) : _port(port),
_asioAcceptor(_asioContext, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)), _messageHandler(_clientsConnected)
{

}

AsioServer::~AsioServer()
{
}

void AsioServer::start()
{
    acceptClientsConnection();
    _threadContext = std::thread([this]() { _asioContext.run(); });
}

void AsioServer::stop()
{
    _asioContext.stop();
	if (_threadContext.joinable())
        _threadContext.join();
}

void AsioServer::update()
{
    for (auto &i : _clientsConnected)
    {
        if (i->isConnected() == false)
        {
            _clientsConnected.erase(std::remove(_clientsConnected.begin(), _clientsConnected.end(), i), _clientsConnected.end());
            break;
        }
    }

    if (_messageList.size() > 0)
    {
        ClientInstanceMessage<MessageType> message = _messageList.front();
        _messageList.pop_front();
        _messageHandler.handleMessage(message);
    }
}

void AsioServer::acceptClientsConnection()
{
    _asioAcceptor.async_accept( [this](std::error_code ec, asio::ip::tcp::socket socket)
	{
        if (!ec)
		{
            std::shared_ptr<ClientInstance> newconnection = std::make_shared<ClientInstance>(_asioContext, std::move(socket), _messageList);

            newconnection->readMessageHeader();

            _clientsConnected.push_back(std::move(newconnection));
        }
        else
		{
			std::cout << "Connexion error: " << ec.message() << "\n";
		}
        acceptClientsConnection();
    });
}