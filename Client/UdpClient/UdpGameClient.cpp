/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** UdpGameClient
*/

#include "UdpGameClient.hpp"

UdpGameClient::UdpGameClient(const std::string &ip, int port) : UdpClient(ip, port)
{
}

UdpGameClient::~UdpGameClient()
{
}


void UdpGameClient::start()
{
    readMessageHeader();
    _threadContext = std::thread([this]() { _asioContext.run(); });
    sendRegisterMessage();
    run();
}

void UdpGameClient::sendRegisterMessage()
{
    Message<MessageType> message;

    message << MessageType::GameRegister;

    sendMessage(message);
}