/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <memory>
#include "TcpClient/TcpClient.hpp"
#include "UdpClient/UdpGameClient.hpp"

class Client {
    public:
        Client();
        ~Client();
        void start();
        void run();
        bool tryConnect(const std::string &ip, int port);


        //Game Handler

        void setPlayerName(const std::string &name);
        void createGame(const std::string &name);
        void joinGame(const std::string &name);
        void leaveGame(const std::string &name);
        void getGames();
        void getPlayersInGame(const std::string &name);

    private:
        void initUdpClient();

    private:
        TcpClient _tcpClient;
        void udpPort;
        std::unique_ptr<UdpGameClient> _udpClient;
};

#endif /* !CLIENT_HPP_ */
