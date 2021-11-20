/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-RtypeClient-thomas1.tricaud
** File description:
** RtypeClient
*/

#ifndef RtypeClient_HPP_
#define RtypeClient_HPP_

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

#include "../Monster/Monster.hpp"

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
        void handleGetGames();
        void manageMusic();
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

        std::string _currentGameName;

        std::shared_ptr<Client> _networkClient;
        std::thread _networkThread;

        std::shared_ptr<DLLloader<IEntityRegister>> _enemyLoader;

        ECS _ecs;
        Monster _monster;
};

#endif /* !RtypeClient_HPP_ */
