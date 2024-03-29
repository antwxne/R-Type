/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-RtypeClient-thomas1.tricaud
** File description:
** RtypeClient
*/

#ifndef RtypeClient_HPP_
#define RtypeClient_HPP_

#include <chrono>
#include <memory>
#include <thread>

#include "../Graphical/SfmlDisplay.hpp"
#include "../Graphical/SfmlParallax.hpp"
#include "../Graphical/SfmlMenu.hpp"
#include "../Graphical/SfmlEventFactory.hpp"
#include "Client.hpp"
#include "../ECS/ECS.hpp"
#include "../ECS/Entity/PlayerEntity.hpp"
#include "../ECS/Entity/EnemyEntity.hpp"
#include "../ECS/Entity/BulletEntity.hpp"
#include "../ECS/system.hpp"
#include "../Graphical/SfmlSoundHandler.hpp"
#include "../DLLloader/DLLloader.hpp"

enum GameState
{
    ConnectMenu,
    MainMenu,
    GameLobby,
    Game,
    Options,
};

class RtypeClient {
    public:
        RtypeClient();
        ~RtypeClient();
        void start();
        void loadEnemyLib(const std::string &filename);
        void stop();

    private:
        void registerComponents();
        void initMenu();
        void run();
        void manageState();
        void manageConnectMenu();
        void manageMainMenu();
        void manageLobbyMenu();
        void manageGame();
        void handleEvents(const sf::Event& event);
        void handleTextInput(const sf::Event& event);
        void handleInitLobby();
        void handleInitGame();
        void handleGetGames();
        void manageMusic();
        void initTextEntities();

        void handleInComingEntities();
        void handleNewEntity(const NetworkEntityInformation &info);
        void handleUpdateEntity(const NetworkEntityInformation &info);
        void updateGamesInfo();

        void handleInCommingDestructionEntity();
        
        void sendControlsToServer();
    private:
        GameState _state;
        bool _stop;

        std::shared_ptr<SfmlDisplay> _graphical;
        SfmlEventFactory _eventFactory;
        SfmlParallax _parallax;
        sf::Sprite _spriteLogo;
        sf::Texture _textureLogo;
        sf::Music _menuMusic;
        sf::Music _gameMusic;
        
        SfmlMenu _connectMenu;
        SfmlMenu _mainMenu;
        SfmlMenu _lobbyMenu;

        SfmlSoundHandler _soundHandler;

        std::string _currentGameName;

        std::shared_ptr<Client> _networkClient;
        std::thread _networkThread;
        ECS _ecs;

        std::map<std::size_t, std::size_t> _serverToClientEntityMap;

        std::list<ControlGame> _gameControlList;
};

#endif /* !RtypeClient_HPP_ */
