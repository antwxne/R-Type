/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** GameInstanceEcs
*/

#ifndef GAMEINSTANCEECS_HPP_
#define GAMEINSTANCEECS_HPP_

#include <chrono>

#include "ECS/ECS.hpp"

typedef std::chrono::high_resolution_clock Clock;

#define NETWORK_ENTITY_SEND_MS_DELAY  100

class GameInstance;

class GameInstanceEcs {
    public:
        GameInstanceEcs(GameInstance &_gameInstance);
        ~GameInstanceEcs();
        void run();
        void handleNewPlayer(int nPlayer);
        void handleCommandPlayer(int nPlayer, ControlGame control);

    private:
        void registerComponents();
        void registerSystems();
        void networkEntityUpdate();
        void handleNetworkGameInfos(const Entity &entity);
        void getCurrentEntityInfo(const Entity &entity);
        bool checkNetworkEntity(const Entity &entity);
        void sendDestructionMessage(const std::vector<std::pair<size_t, RaisedEvent>> &events);
        void handleRaisedEvents();
    private:
        ECS _ecs;
        GameInstance &_gameInstance;
        std::chrono::_V2::system_clock::time_point _networkSendClock;

        std::map<int, size_t> _playerToEntityMap;

        std::vector<std::pair<size_t, RaisedEvent>> _raisedEvents;
};

#endif /* !GAMEINSTANCEECS_HPP_ */
