/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** UdpClientInstance
*/

#include "UdpClientInstance.hpp"

UdpClientInstance::UdpClientInstance(asio::io_context& asioContext, asio::ip::udp::socket socket)
: _asioContext(asioContext), _socket(std::move(socket))
{
    _socket.async_send_to();
}

UdpClientInstance::~UdpClientInstance()
{
}
