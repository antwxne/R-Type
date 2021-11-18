/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-RtypeClient-thomas1.tricaud
** File description:
** RtypeClient
*/

#include "RtypeClient.hpp"
#include "ECS/System/EventSystem/EventSystem.hpp"
#include "ECS/System/EventSystem/EventCallback.hpp"
#include "ECS/component.hpp"
#include <iostream>

RtypeClient::RtypeClient()
{
    srand(time(NULL));
    _graphical = std::make_shared<SfmlDisplay>();
    _textureLogo.loadFromFile("assets/sprites/r_type_logo.png");
    _spriteLogo.setTexture(_textureLogo);
    _menuMusic.openFromFile("assets/music/space_oddity.ogg");
    _gameMusic.openFromFile("assets/music/red-alert.ogg");
    sf::Music _gameMusic;
    _stop = false;
    _state = GameState::Game;
    initMenu();
    registerComponents();
}

RtypeClient::~RtypeClient()
{
}

void RtypeClient::stop()
{
    if (_networkClient)
        _networkClient->stop();
    if (_networkThread.joinable())
        _networkThread.join();
}

void RtypeClient::initMenu()
{
    _connectMenu.addButton("Name: ", 50, true, 10, false);
    _connectMenu.addButton("IP: ", 50, true, -1, false);
    _connectMenu.addButton("Port: ", 50, true, -1, false);
    _connectMenu.addButton("Connect", 70, false, -1, true);

    _mainMenu.addButton("Refresh", 50, false, -1, true);
    _mainMenu.addButton("Create game : ", 50, true, 12, true);
}

void RtypeClient::registerComponents()
{
    _ecs.registerComponent<Position>();
    _ecs.registerComponent<Speed>();
    _ecs.registerComponent<Acceleration>();
    _ecs.registerComponent<Texture>();
    _ecs.registerComponent<Acceleration>();
    _ecs.registerComponent<Scale>();
    _ecs.registerComponent<Rotate>();
    _ecs.registerComponent<Color>();
    _ecs.registerComponent<SfmlSprite>();
    _ecs.registerComponent<Collision>();
    _ecs.registerComponent<Hitbox>();
    _ecs.registerComponent<Tag>();
    _ecs.registerComponent<Life>();
    _ecs.registerComponent<Rectangle>();
    _ecs.registerComponent<Firerate>();
    _ecs.registerComponent<AI>();
}

void RtypeClient::start()
{
    PlayerEntity _pe({150, 50}, ColorType::None);
    EnemyEntity _ee({1050, 50});
    EnemyEntity _ee2({1050, 50});
    EnemyEntity _ee3({1050, 50});
    EnemyEntity _ee4({1050, 50});
    EnemyEntity _ee5({1050, 50});
    BulletEntity _be({150, 800}, true);
    _pe.create(_ecs.getComponentManager(), _ecs.getEntityManager());
    _ee.create(_ecs.getComponentManager(), _ecs.getEntityManager());
    _ee2.create(_ecs.getComponentManager(), _ecs.getEntityManager());
    _ee3.create(_ecs.getComponentManager(), _ecs.getEntityManager());
    _ee4.create(_ecs.getComponentManager(), _ecs.getEntityManager());
    _ee5.create(_ecs.getComponentManager(), _ecs.getEntityManager());

    auto &draw = _ecs.registerSystem<SfmlDrawSystem>();
    _ecs.registerSystem<MoveSystem>();
    _ecs.registerSystem<AISystem>();
    draw.setDisplay(_graphical);

    auto &evtManager = _ecs.registerSystem<EventSystem>();
    // BIND une fonction statique a un evenement
    evtManager.subscribeToEvent(ControlGame::RIGHT, _pe.getEntity(), std::bind(EventCallback::changeAccelerationRIGHT, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    evtManager.subscribeToEvent(ControlGame::UP, _pe.getEntity(), std::bind(EventCallback::changeAccelerationUP, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    evtManager.subscribeToEvent(ControlGame::DOWN, _pe.getEntity(), std::bind(EventCallback::changeAccelerationDOWN, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    evtManager.subscribeToEvent(ControlGame::LEFT, _pe.getEntity(), std::bind(EventCallback::changeAccelerationLEFT, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    evtManager.subscribeToEvent(ControlGame::SPACE, _pe.getEntity(), std::bind(EventCallback::shoot, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

    run();
}

void RtypeClient::run()
{
    while (_graphical->getWindow()->isOpen())
    {
        while (_graphical->getWindow()->pollEvent(_graphical->getEvent()))
        {
            sf::Event event = _graphical->getEvent();

            if (event.type == sf::Event::Closed)
                _graphical->getWindow()->close();
            else if (event.type == sf::Event::KeyPressed || event.type == sf::Event::TextEntered)
                handleEvents(event);
        }
        _graphical->clear();
        _parallax.update();
        _parallax.draw(*_graphical->getWindow());
        manageState();
        manageMusic();
        _graphical->display();
    }
    stop();
}

void RtypeClient::manageMusic()
{
    if (_state == GameState::Game)
    {
        if (_gameMusic.getStatus() != sf::Music::Playing)
            _gameMusic.play();
        if (_menuMusic.getStatus() == sf::Music::Playing)
            _menuMusic.stop();
    }
    else
    {
        if (_gameMusic.getStatus() == sf::Music::Playing)
            _gameMusic.stop();
        if (_menuMusic.getStatus() != sf::Music::Playing)
            _menuMusic.play();
    }
}


void RtypeClient::handleEvents(const sf::Event& event)
{
    ControlGame control = _eventFactory.getEventType(event);
    if (control != ControlGame::NONE)
    {
        switch (_state)
        {
        case GameState::ConnectMenu:
            _connectMenu.handleEvent(control);
            break;
        case GameState::MainMenu:
            _mainMenu.handleEvent(control);
            break;
        case GameState::GameLobby:
            _lobbyMenu.handleEvent(control);
            break;
        case GameState::Game:
            _ecs.getSystem<EventSystem>().setEvents(control);
            /* code */
            break;
        default:
            return;
        }
    }
    else if (event.type == sf::Event::TextEntered)
    {
        handleTextInput(event);
    }
}

void RtypeClient::handleTextInput(const sf::Event& event)
{
    std::string input = _eventFactory.getTextEntered(event);
    switch (_state)
    {
        case GameState::ConnectMenu:
            _connectMenu.handleTextInput(input);
            break;
        case GameState::MainMenu:
            _mainMenu.handleTextInput(input);
            break;
        case GameState::GameLobby:
            _lobbyMenu.handleTextInput(input);
            break;
        case GameState::Game:
            /* code */
            break;
        default:
            return;
        }
}

void RtypeClient::manageState()
{
    switch (_state)
    {
    case GameState::ConnectMenu:
        manageConnectMenu();
        break;
    case GameState::MainMenu:
        manageMainMenu();
        break;
    case GameState::GameLobby:
        manageLobbyMenu();
        break;
    case GameState::Game:
        this->manageGame();
        break;
    default:
        return;
    }
}

void RtypeClient::manageConnectMenu()
{
    _graphical->getWindow()->draw(_spriteLogo);
    _connectMenu.draw(_graphical->getWindow());
    if (_networkClient && _networkClient->isTcpConnected())
    {
        _state = GameState::MainMenu;
        _networkThread = std::thread(&Client::start, _networkClient);
        _networkClient->setPlayerName(_connectMenu.getButtonText(0));
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        _networkClient->getGames();
    }
    if (_connectMenu.isValided())
    {
        _connectMenu.resetValided();
        if (_networkClient == nullptr)
            _networkClient = std::make_shared<Client>();

        try
        {
            std::string sPort = _connectMenu.getButtonText(2);
            int port = std::stoi(sPort);
            _networkClient->tryConnect(_connectMenu.getButtonText(1), port);
        }
        catch (std::exception &e)
        {
            return;
        }
    }
}

void RtypeClient::manageMainMenu()
{
    _graphical->getWindow()->draw(_spriteLogo);
    _mainMenu.draw(_graphical->getWindow());
    if (_networkClient->isNewGameListAvailable())
        handleGetGames();
    if (_mainMenu.isValided())
    {
        _mainMenu.resetValided();
        if (_mainMenu.getSelectedIndex() == 0)
        {
            _networkClient->resetGameList();
            _networkClient->getGames();
            handleGetGames();
        }
        else if (_mainMenu.getSelectedIndex() == 1)
        {
            _networkClient->createGame(_mainMenu.getButtonText(1));
            _currentGameName = _mainMenu.getButtonText(1);
        }
        else
        {
            std::string name = _mainMenu.getButtonText(_mainMenu.getSelectedIndex()).substr(0, _mainMenu.getButtonText(_mainMenu.getSelectedIndex()).length() - 6);
            _networkClient->joinGame(name);
            _currentGameName = name;
        }
    }
    if (_networkClient->isInGame())
    {
        _state = GameState::GameLobby;
        _networkClient->getPlayersInGame(_currentGameName);
    }
}

void RtypeClient::handleGetGames()
{
    _mainMenu.resetButtons();
    _mainMenu.addButton("Refresh", 50, false, -1, true);
    _mainMenu.addButton("Create game: ", 50, true, 12, true);
    for (auto &i : _networkClient->getGameList())
    {
        std::string nbPLayer;
        nbPLayer += std::to_string((int) i.second);
        std::string name = i.first + " - " + nbPLayer + "/4";
        _mainMenu.addButton(name, 50, false, -1, true);
    }
}


void RtypeClient::handleInitLobby()
{
    _lobbyMenu.resetTexts();
    _lobbyMenu.resetButtons();

    _lobbyMenu.addButton("Start " + _currentGameName, 70, false, -1, true);

    for (auto &i : _networkClient->getPlayersInGameList())
    {
        _lobbyMenu.addText("- " + i, 30);
    }
    _lobbyMenu.addButton("Refresh", 50, false, -1, true);
}

void RtypeClient::manageLobbyMenu()
{
    _graphical->getWindow()->draw(_spriteLogo);
    _lobbyMenu.draw(_graphical->getWindow());

    if (_networkClient->isNewPlayerListAvailable())
    {
        handleInitLobby();
    }
    if (_lobbyMenu.isValided())
    {
        if (_lobbyMenu.getSelectedIndex() == 0)
        {
            _state = GameState::Game;
        }
        else
        {
            _networkClient->getPlayersInGame(_currentGameName);
        }
    }
}

void RtypeClient::manageGame()
{
    _ecs.getSystem<EventSystem>().update();
    _ecs.getSystem<AISystem>().update();
    _ecs.getSystem<MoveSystem>().update();
    _ecs.getSystem<SfmlDrawSystem>().update();
    _ecs.garbageCollector();
}