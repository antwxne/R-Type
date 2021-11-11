/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** GameInstance
*/

#ifndef GAMEINSTANCE_HPP_
#define GAMEINSTANCE_HPP_

#include <string>
#include <vector>
#include <memory>

#include "IAsioGameInstance.hpp"
#include "../UdpServer/GameUdpServer.hpp"

enum GameInstanceState
{
    WaitingScreen,
    Game
};

class GameInstance : public IAsioGameInstance {
    public:
        GameInstance(const std::string &instanceName, char maxPlayers);
        ~GameInstance();
        void run() override;
        void stop() override;
        void startGame() override;

        bool addClient(std::shared_ptr<TcpClientInstance> client) override;
        bool removeClient(std::shared_ptr<TcpClientInstance> client) override;
        void removeDisconnectedClient(const std::string &clientName);
        
        std::string getName() const;
        std::list<std::string> getPlayers();
        char getNPlayers() const;

    protected:
    private:
        bool _run;
        GameInstanceState _state;
        std::string _name;
        char _maxPlayers;
        char _nbPlayers;
        std::vector<std::shared_ptr<TcpClientInstance>> _clients;

        std::unique_ptr<GameUdpServer> _udpGameServer;
};

#endif /* !GAMEINSTANCE_HPP_ */