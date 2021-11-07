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
#include "IAsioGameInstance.hpp"

enum GameInstanceState
{
    WaitingScreen,
    Game
};

class GameInstance :public IAsioGameInstance {
    public:
        GameInstance(const std::string &instanceName, int maxPlayers);
        ~GameInstance();
        void run() override;
        void setHost(std::shared_ptr<TcpClientInstance> client) override;
        bool addClient(std::shared_ptr<TcpClientInstance> client) override;
        void startGame() override;
        std::string getName();
    protected:
    private:
        GameInstanceState _state;
        std::string _name;
        int _maxPlayers;
        int _nbPlayers;
        std::shared_ptr<TcpClientInstance> _host;
        std::vector<std::shared_ptr<TcpClientInstance>> _clients;
};

#endif /* !GAMEINSTANCE_HPP_ */
