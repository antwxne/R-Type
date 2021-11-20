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
#include "ECS/Entity/SoundEntity.hpp"
#include "ECS/Entity/RoundEntity.hpp"
#include <iostream>
#include "ECS/system.hpp"

typedef std::chrono::high_resolution_clock Clock;

RtypeClient::RtypeClient()
{
    srand(time(NULL));
    _graphical = std::make_shared<SfmlDisplay>();
    _textureLogo.loadFromFile("assets/sprites/r_type_logo.png");
    _spriteLogo.setTexture(_textureLogo);

    _menuMusic.openFromFile("assets/music/space_oddity.ogg");
    _gameMusic.openFromFile("assets/music/red-alert.ogg");
    _menuMusic.setLoop(true);
    _gameMusic.setLoop(true);

    sf::Music _gameMusic;
    _stop = false;
    _state = GameState::ConnectMenu;
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
    _ecs.registerComponent<SfmlSound>();
    _ecs.registerComponent<MoveClock>();
    _ecs.registerComponent<Round>();
}

void RtypeClient::start()
{
    auto &draw = _ecs.registerSystem<SfmlDrawSystem>();
    _ecs.registerSystem<MoveSystem>();
    draw.setDisplay(_graphical);
    _ecs.registerSystem<SfmlSoundSystem>();
    

    auto &evtManager = _ecs.registerSystem<EventSystem>();
    run();
}

void RtypeClient::run()
{

    while (_graphical->getWindow()->isOpen()) {
        while (_graphical->getWindow()->pollEvent(_graphical->getEvent())) {
            const sf::Event &event = _graphical->getEvent();
            if (event.type == sf::Event::Closed)
                _graphical->getWindow()->close();
            else if (event.type == sf::Event::KeyPressed ||
                event.type == sf::Event::TextEntered) {
                handleEvents(event);
            }
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
    if (_state == GameState::Game) {
        if (_menuMusic.getStatus() == sf::Music::Playing)
            _menuMusic.stop();
    }
    else {
        if (_gameMusic.getStatus() == sf::Music::Playing)
            _gameMusic.stop();
        if (_menuMusic.getStatus() != sf::Music::Playing)
            _menuMusic.play();
    }
}

void RtypeClient::handleEvents(const sf::Event &event)
{
    ControlGame control = _eventFactory.getEventType(event);

    if (control != ControlGame::NONE) {
        switch (_state) {
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
            _gameControlList.push_back(control);
            break;
        default:
            return;
        }
    } else if (event.type == sf::Event::TextEntered) {
        handleTextInput(event);
    }
}

void RtypeClient::handleTextInput(const sf::Event &event)
{
    std::string input = _eventFactory.getTextEntered(event);
    switch (_state) {
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
    switch (_state) {
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
        manageGame();
        break;
    default:
        return;
    }
}

void RtypeClient::manageConnectMenu()
{
    _graphical->getWindow()->draw(_spriteLogo);
    _connectMenu.draw(_graphical->getWindow());
    if (_networkClient && _networkClient->isTcpConnected()) {
        _state = GameState::MainMenu;
        _networkThread = std::thread(&Client::start, _networkClient);
        _networkClient->setPlayerName(_connectMenu.getButtonText(0));
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        _networkClient->getGames();
    }
    if (_connectMenu.isValided()) {
        _connectMenu.resetValided();
        if (_networkClient == nullptr)
            _networkClient = std::make_shared<Client>();

        try {
            std::string sPort = _connectMenu.getButtonText(2);
            int port = std::stoi(sPort);
            _networkClient->tryConnect(_connectMenu.getButtonText(1), port);
        } catch (std::exception &e) {
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
    if (_mainMenu.isValided()) {
        _mainMenu.resetValided();
        if (_mainMenu.getSelectedIndex() == 0) {
            _networkClient->resetGameList();
            _networkClient->getGames();
            handleGetGames();
        } else if (_mainMenu.getSelectedIndex() == 1) {
            if (_mainMenu.getButtonText(1).size() > 0)
            {
                _networkClient->createGame(_mainMenu.getButtonText(1));
                _currentGameName = _mainMenu.getButtonText(1);
            }
        } else {
            std::string name = _mainMenu.getButtonText(
                _mainMenu.getSelectedIndex()).substr(0,
                _mainMenu.getButtonText(_mainMenu.getSelectedIndex()).length() -
                    6);
            _networkClient->joinGame(name);
            _currentGameName = name;
        }
    }
    if (_networkClient->isInGame()) {
        _state = GameState::GameLobby;
        _networkClient->getPlayersInGame(_currentGameName);
    }
}

void RtypeClient::handleGetGames()
{
    _mainMenu.resetButtons();
    _mainMenu.addButton("Refresh", 50, false, -1, true);
    _mainMenu.addButton("Create game: ", 50, true, 12, true);
    for (auto &i: _networkClient->getGameList()) {
        std::string nbPLayer;
        nbPLayer += std::to_string((int)i.second);
        std::string name = i.first + " - " + nbPLayer + "/4";
        _mainMenu.addButton(name, 50, false, -1, true);
    }
}

void RtypeClient::handleInitLobby()
{
    _lobbyMenu.resetTexts();
    _lobbyMenu.resetButtons();

    _lobbyMenu.addButton("Start " + _currentGameName, 70, false, -1, true);

    for (auto &i: _networkClient->getPlayersInGameList()) {
        _lobbyMenu.addText("- " + i, 30);
    }
    _lobbyMenu.addButton("Refresh", 50, false, -1, true);
}

void RtypeClient::manageLobbyMenu()
{
    _graphical->getWindow()->draw(_spriteLogo);
    _lobbyMenu.draw(_graphical->getWindow());

    if (_networkClient->isNewPlayerListAvailable()) {
        handleInitLobby();
    }
    if (_lobbyMenu.isValided())
    {
        _lobbyMenu.resetValided();
        if (_lobbyMenu.getSelectedIndex() == 0)
        {
            _networkClient->startGame(_currentGameName);
        }
        else
        {
            _networkClient->getPlayersInGame(_currentGameName);
        }
    }
    if (_networkClient->isGameStarting())
    {
        handleInitGame();
        _state = GameState::Game;
    }
}

void RtypeClient::handleInitGame()
{
    _networkClient->initUdpClient();
}


void RtypeClient::manageGame()
{
    try
    {
        _ecs.getSystem<MoveSystem>().update();
        _ecs.getSystem<SfmlDrawSystem>().update();
        _ecs.getSystem<SfmlSoundSystem>().update();
        _ecs.graphicalGarbageCollector();
        handleInComingEntities();
        handleInCommingDestructionEntity();
        sendControlsToServer();
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void RtypeClient::sendControlsToServer()
{
    _networkClient->sendCommands(_gameControlList);
    _gameControlList.clear();
}

void RtypeClient::handleInComingEntities()
{
    std::list<NetworkEntityInformation> entities = _networkClient->getEntitiesInfos();

    for (auto & i : entities)
    {
        if (_serverToClientEntityMap.find(i.entity) == _serverToClientEntityMap.end())
        {
            handleNewEntity(i);
        }
        else
        {
            handleUpdateEntity(i);
        }
    }
    _networkClient->clearEntitiesInfos();
}

void RtypeClient::handleInCommingDestructionEntity()
{
    std::list<std::pair<size_t, RaisedEvent>> entities = _networkClient->getEntitiesRaisedEvent();
    
    for (auto &i :entities)
    {
        if (i.second == RaisedEvent::ENTITY_DEAD)
        {
            _ecs.getEntityManager()->destroy(_serverToClientEntityMap[i.first]);
            _serverToClientEntityMap.erase(i.first);

            SoundEntity soundE(SoundType::Explosion);
            soundE.create(_ecs.getComponentManager(), _ecs.getEntityManager());
        }
        else if (i.second == RaisedEvent::SHOT)
        {
            SoundEntity sound(SoundType::Shot);
            sound.create(_ecs.getComponentManager(), _ecs.getEntityManager());
        }
    }
    _networkClient->resetRaisedEvent();

}

void RtypeClient::handleNewEntity(const NetworkEntityInformation &info)
{
    size_t newEntity;
    
    _ecs.createEntity() >> newEntity;

    
    _serverToClientEntityMap[info.entity] = newEntity;

    std::shared_ptr<sf::Sprite> sprite = std::make_shared<sf::Sprite>();

    sprite->setTextureRect(info.textureRect);
    _ecs.subToComponent(newEntity, Rotate{0});
    _ecs.subToComponent(newEntity, Color{ColorType::None});
    _ecs.subToComponent(newEntity, Texture{TextureType::Enemy});
    _ecs.subToComponent(newEntity, Scale{0, 0});
    _ecs.subToComponent(newEntity, SfmlSprite{sprite, {0,0,0,0}, 0,0, 0});
    _ecs.subToComponent(newEntity, Speed{0});
    _ecs.subToComponent(newEntity, Acceleration{0, 0});
    _ecs.subToComponent(newEntity, Position{0,0});
    _ecs.subToComponent(newEntity, MoveClock{7});

    handleUpdateEntity(info);
}

void RtypeClient::handleUpdateEntity(const NetworkEntityInformation &info)
{
    size_t clientEntity = _serverToClientEntityMap[info.entity];

    Rotate &rotate = _ecs.getComponent<Rotate>(clientEntity).value();
    Color &color = _ecs.getComponent<Color>(clientEntity).value();
    Texture &texture = _ecs.getComponent<Texture>(clientEntity).value();
    Scale &scale = _ecs.getComponent<Scale>(clientEntity).value();
    Speed &speed = _ecs.getComponent<Speed>(clientEntity).value();
    Acceleration & acceleration = _ecs.getComponent<Acceleration>(clientEntity).value();
    Position &position = _ecs.getComponent<Position>(clientEntity).value();
    SfmlSprite &sprite = _ecs.getComponent<SfmlSprite>(clientEntity).value();

    rotate = info.rotate;
    color = info.color;
    texture = info.textureType;
    scale = info.scale;
    speed = info.speed;
    acceleration = info.acceleration;
    position = info.position;
    sprite.animationSpeed = info.animationSpeed;
    sprite.totalRect = info.totalTextureRect;
    sprite.textureRect = info.textureRect;
}