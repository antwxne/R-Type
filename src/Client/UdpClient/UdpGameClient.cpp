/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** UdpGameClient
*/

#include "UdpGameClient.hpp"

UdpGameClient::UdpGameClient(const std::string &ip, int port) : UdpClient(ip, port), _gameHandler(*this)
{
}

UdpGameClient::~UdpGameClient()
{
}

void UdpGameClient::run()
{
    if (_messageList.size() > 0)
    {
        Message<MessageType> message = _messageList.front();
        _messageList.pop_front();
        _gameHandler.handleMessage(message);
    }
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

void UdpGameClient::addEntityInfo(const NetworkEntityInformation& info)
{
    _entitiesInfos.push_back(info);
}

std::list<NetworkEntityInformation> &UdpGameClient::getEntitiesInfos()
{
    return _entitiesInfos;
}

void UdpGameClient::resetEntitiesList()
{
    _entitiesInfos.clear();
}

void UdpGameClient::sendCommands(const std::list<ControlGame> &controls)
{
    for (auto &i : controls)
    {
        Message<MessageType> message;

        message << MessageType::GameCommand;
        message << i;

        sendMessage(message);
    }
}

void UdpGameClient::addEntityRaisedEvent(size_t entity, RaisedEvent event)
{
    _entitiesRaisedEvent.push_back({entity, event});
}

std::list<std::pair<size_t, RaisedEvent>> &UdpGameClient::getEntitiesRaisedEvent()
{
    return _entitiesRaisedEvent;
}

void UdpGameClient::resetRaisedEvent()
{
    _entitiesRaisedEvent.clear();
}