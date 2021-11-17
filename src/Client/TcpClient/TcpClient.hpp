/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Client
*/

#ifndef TCPCLIENT_HPP_
#define TCPCLIENT_HPP_

#include <asio.hpp>
#include <list>

#include "Message.hpp"
#include "network.hpp"
#include "TcpClientConnection.hpp"
#include "TcpClientMessageHandler.hpp"

class TcpClient
{
    public:
        TcpClient();
        ~TcpClient();
        void start();
        void run();
        void stop();

        void sendMessage(Message<MessageType> &message);
        bool tryConnect(const std::string &ip, int port);

        std::string getIp() const;

        void addGame(const std::string &name, char nbPlayers);
        std::list<std::pair<std::string, char>> &getGames();
        void resetGameList();
        bool isNewGameListAvailable();
        void setGameListAvaible(bool value);

        void addPlayerInGame(const std::string &name);
        std::list<std::string> &getPlayersInGame();
        void resetPlayerList();
        bool isNewPlayerListAvailable();
        void setPlayerListAvaible(bool value);
        
        bool isConnected();

        bool isInGame();
        void setInGame(bool value);

    private:
        void update();
    private:
        int _port;
        std::string _ip;

        asio::io_context _asioContext;
        asio::executor_work_guard<decltype(_asioContext.get_executor())> work{_asioContext.get_executor()};

		std::thread _threadContext;

        std::shared_ptr<TcpClientConnection> _connection;
        std::list<Message<MessageType>> _messageList;
        TcpClientMessageHandler _messageHandler;

        std::list<std::pair<std::string, char>> _gamesList;
        bool _newGameList;

        std::list<std::string> _inGamePlayerList;
        bool _newInGamePlayerList;

        bool _inGame;
};

#endif /* !CLIENT_HPP_ */
