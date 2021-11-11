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
        GameUdpServer(int nbPlayers);
        ~GameUdpServer();
        void run() override;
        void sendMessageToPlayer(GameUdpMessage<MessageType> &message, int nPlayer);

    private:
        void handleHeaderRecieve(const asio::error_code& error, std::size_t size) override;
        void handleBodyRecieve(const asio::error_code& error, std::size_t size) override;

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
