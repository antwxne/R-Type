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
    std::cout << "Send register message\n";
    Message<MessageType> message;

    message << MessageType::GameRegister;

    sendMessage(message);
}

void UdpGameClient::sendCommand(ControlGame control)
{
    std::cout << "Command message\n";

    Message<MessageType> message;

    message << MessageType::GameCommand;

    message << control;

    sendMessage(message);
}