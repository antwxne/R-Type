/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** UdpClient
*/

#include "UdpClient.hpp"
#include "network.hpp"
#include "Message.hpp"

UdpClient::UdpClient(int port) :
_socket(_ioContext)
{
    _socket.open(asio::ip::udp::v4());
    _serverEndpoint = asio::ip::udp::endpoint(asio::ip::address::from_string("127.0.0.1"), 8070);
}

UdpClient::~UdpClient()
{
}

void UdpClient::start()
{
    Message<MessageType> m;

    m << MessageType::CreateGame;

    std::cout << _socket.send_to(asio::buffer(m.getHeaderPtr(), m.getHeaderSize()), _serverEndpoint) << "\n";
    std::cout << _socket.send_to(asio::buffer(m.getHeaderPtr(), m.getHeaderSize()), _serverEndpoint) << "\n";
    std::cout << _socket.send_to(asio::buffer(m.getHeaderPtr(), m.getHeaderSize()), _serverEndpoint) << "\n";
}