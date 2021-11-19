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
#include <map>

class GameUdpServer : public UdpAsioServer
{
    public:
        GameUdpServer(int port, int nbPlayers);
        ~GameUdpServer();
        void run() override;
        void sendMessageToPlayer(Message<MessageType> &message, int nPlayer);
        void readMessageHeader() override;
        void readMessageBody() override;
    private:
        bool checkPlayerBinded(asio::ip::udp::endpoint endpoint);
        bool handlePlayerClient(asio::ip::udp::endpoint endpoint);
    private:
        std::map<asio::ip::udp::endpoint, int> _bindMap;
        int _nbPlayers;
        int _bindedPlayers;

        std::list<GameUdpMessage<MessageType>> _gameMessageList;
        UdpGameMessageHandler _gameMessageHandler;

};

#endif /* !GAMEUDPSERVER_HPP_ */
