/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** GameUdpServer
*/

#ifndef GAMEUDPSERVER_HPP_
#define GAMEUDPSERVER_HPP_

#include "UdpAsioServer.hpp"
#include "GameUdpMessage.hpp"
#include "UdpGameMessageHandler.hpp"
#include "network.hpp"
#include "Graphical/SfmlEventFactory.hpp"
#include <chrono>
#include <map>

class GameInstance;

class GameUdpServer : public UdpAsioServer
{
    public:
        GameUdpServer(GameInstance &gameInstance, int port, int nbPlayers);
        ~GameUdpServer();
        void run() override;
        void sendMessageToAll(Message<MessageType> &message);
        void readMessageHeader() override;
        void readMessageBody() override;

        void handleRegister(int nPlayer);
        void handleClientCommand(int nPlayer, ControlGame control);

    private:
        bool checkPlayerBinded(asio::ip::udp::endpoint endpoint);
        bool handlePlayerClient(asio::ip::udp::endpoint endpoint);
    private:
        std::map<asio::ip::udp::endpoint, int> _bindMap;
        int _nbPlayers;
        int _bindedPlayers;

        std::list<GameUdpMessage<MessageType>> _gameMessageList;
        UdpGameMessageHandler _gameMessageHandler;

        GameInstance &_gameInstance;
};

#endif /* !GAMEUDPSERVER_HPP_ */
