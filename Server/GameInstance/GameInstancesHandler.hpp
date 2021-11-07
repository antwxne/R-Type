/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** GameInstancesHandler
*/

#ifndef GAMEINSTANCESHANDLER_HPP_
#define GAMEINSTANCESHANDLER_HPP_

#include <thread>
#include <list>
#include <string>
#include "../TcpServer/TcpClientInstance.hpp"
#include "GameInstance.hpp"

class GameInstancesHandler {
    public:
        GameInstancesHandler(int maxGames);
        ~GameInstancesHandler();
        bool addGame(const std::string &gameName, std::shared_ptr<TcpClientInstance> &host);
        bool joinGame(const std::string &gameName, std::shared_ptr<TcpClientInstance> &client);
        void update();
    protected:
    private:
        int _maxGames;
        int _nbGames;
        std::list<std::thread> _gamesThread;
        std::list<std::shared_ptr<GameInstance>> _gamesInstances;
};

#endif /* !GAMEINSTANCESHANDLER_HPP_ */
