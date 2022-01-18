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
#include "NetworkEntityInformation.hpp"

class Client {
    public:
        Client();
        ~Client();
        void start();
        void run();
        bool tryConnect(const std::string &ip, int port);
        void stop();
        bool isTcpConnected();
        
        //Game Handler

        void setPlayerName(const std::string &name);
        void createGame(const std::string &name);
        void joinGame(const std::string &name);
        void leaveGame(const std::string &name);
        void getGames();
        void getPlayersInGame(const std::string &name);
        void startGame(const std::string &name);

        std::list<std::pair<std::string, char>> &getGameList();
        void resetGameList();
        bool isNewGameListAvailable();

        std::list<std::string> &getPlayersInGameList();
        bool isNewPlayerListAvailable();

        bool isInGame();
        bool isGameStarting();

        // Udp Handler

        int getUdpPort();
        void initUdpClient();

        std::list<NetworkEntityInformation> &getEntitiesInfos();
        void clearEntitiesInfos();

        std::list<std::pair<std::size_t, RaisedEvent>> &getEntitiesRaisedEvent();
        void resetRaisedEvent();

        int getGameScore();
        int getGameRound();

        void sendCommands(const std::list<ControlGame> &controls);



    private:

    private:
        TcpClient _tcpClient;
        bool _stop;
        std::unique_ptr<UdpGameClient> _udpClient;
};

#endif /* !CLIENT_HPP_ */
