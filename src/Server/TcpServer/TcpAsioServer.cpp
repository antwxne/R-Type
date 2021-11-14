/*
** EPITECH PROJECT, 2021
** B-CPP-500-PAR-5-1-babel-alan.sigal
** File description:
** TcpAsioServer
*/

#include "TcpAsioServer.hpp"
#include <iostream>

TcpAsioServer::TcpAsioServer(int port) : _port(port),
_asioAcceptor(_asioContext, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)),
_messageHandler(_clientsConnected, *this), gamesHandler(5)
{

}

TcpAsioServer::~TcpAsioServer()
{
}

void TcpAsioServer::run()
{
    while (1)   
    {
        update();
        sleep(0.01);
    }
}

void TcpAsioServer::start()
{
    std::cout << "Listening on port " << _port <<  "..." << std::endl;
    acceptClientsConnection();
    _threadContext = std::thread([this]() { _asioContext.run(); });
    run();
}

void TcpAsioServer::stop()
{
    _asioContext.stop();
	if (_threadContext.joinable())
        _threadContext.join();
}

void TcpAsioServer::update()
{
    gamesHandler.update();
    for (auto &i : _clientsConnected)
    {
        if (i->isConnected() == false)
        {
            onClientDisconnected(i);
            _clientsConnected.erase(std::remove(_clientsConnected.begin(), _clientsConnected.end(), i), _clientsConnected.end());
            break;
        }
    }

    if (_messageList.size() > 0)
    {
        TcpClientInstanceMessage<MessageType> message = _messageList.front();
        _messageList.pop_front();
        _messageHandler.handleMessage(message);
    }
}

void TcpAsioServer::acceptClientsConnection()
{
    _asioAcceptor.async_accept( [this](std::error_code ec, asio::ip::tcp::socket socket)
	{
        if (!ec)
		{
            onClientConnected(socket);
        }
        else
		{
			std::cout << "Connexion error: " << ec.message() << "\n";
		}
        acceptClientsConnection();
    });
}

void TcpAsioServer::onClientConnected(asio::ip::tcp::socket &socket)
{
    std::cout << "New client connected: " << socket.remote_endpoint() << std::endl;

    std::shared_ptr<TcpClientInstance> newconnection = std::make_shared<TcpClientInstance>(_asioContext, std::move(socket), _messageList);
    newconnection->readMessageHeader();
    _clientsConnected.push_back(std::move(newconnection));
}

void TcpAsioServer::onClientDisconnected(std::shared_ptr<TcpClientInstance> &client)
{
    gamesHandler.removeDisconnectedClient(client->informations.getName());
    std::cout << "A Client disconnected" << std::endl;
}