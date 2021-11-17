/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-RtypeClient-thomas1.tricaud
** File description:
** RtypeClient
*/

#include "RtypeClient.hpp"
#include <iostream>

RtypeClient::RtypeClient() : _state(GameState::ConnectMenu)
{
    _textureLogo.loadFromFile("assets/sprites/r_type_logo.png");
    _spriteLogo.setTexture(_textureLogo);
    initMenu();
    _stop = false;
}

RtypeClient::~RtypeClient()
{
}

void RtypeClient::stop()
{
    if (_networkClient)
        _networkClient->stop();
    _networkThread.join();
}

void RtypeClient::initMenu()
{
    _connectMenu.addButton("Name: ", 50, true, false);
    _connectMenu.addButton("IP: ", 50, true, false);
    _connectMenu.addButton("Port: ", 50, true, false);
    _connectMenu.addButton("Connect", 70, false, true);

    _mainMenu.addButton("Refresh", 50, false, true);
    _mainMenu.addButton("Create game : ", 50, true, true);

}

void RtypeClient::start()
{
    //ecs.registerComponent<Position>();
    /*ecs.registerComponent<Texture>();
    ecs.registerComponent<Scale>();
    ecs.registerComponent<Rotate>();
    ecs.registerComponent<Color>();
    ecs.registerComponent<SfmlSprite>();
*/
    /*auto draw = ecs.registerSystem<SfmlDrawSystem>();

    Entity player = ecs.createEntity();

    ecs.subToComponent(player, Position{50, 50});
    ecs.subToComponent(player, Texture{TextureType::Player});
    ecs.subToComponent(player, Scale{1});
    ecs.subToComponent(player, Color{ColoRtypeClient::None});
    ecs.subToComponent(player, SfmlSprite{sf::Sprite()});*/
    run();
}

void RtypeClient::run()
{
    while (_graphical.getWindow().isOpen())
    {
        while (_graphical.getWindow().pollEvent(_graphical.getEvent()))
        {
            sf::Event event = _graphical.getEvent();

            if (event.type == sf::Event::Closed)
                _graphical.getWindow().close();
            else if (event.type == sf::Event::KeyPressed || event.type == sf::Event::TextEntered)
                handleEvents(event);
        }
        _graphical.clear();
        _parallax.update();
        _parallax.draw(_graphical.getWindow());
        manageState();
        _graphical.display();
    }
    stop();
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
        /* code */
        break;
    default:
        return;
    }
}

void RtypeClient::manageConnectMenu()
{
    _graphical.getWindow().draw(_spriteLogo);
    _connectMenu.draw(_graphical.getWindow());
    if (_connectMenu.isValided())
    {
        _connectMenu.resetValided();
        if (_networkClient == nullptr)
            _networkClient = std::make_shared<Client>();

        try
        {
            std::string sPort = _connectMenu.getButtonText(2);
            int port = std::stoi(sPort);
            if (_networkClient->tryConnect(_connectMenu.getButtonText(1), port))
            {
                _state = GameState::MainMenu;
                _networkThread = std::thread(&Client::start, _networkClient);
                _networkClient->setPlayerName(_connectMenu.getButtonText(0));
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                _networkClient->getGames();
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                handleGetGames();
            }
        }
        catch (std::exception &e)
        {
            return;
        }
    }
}

void RtypeClient::manageMainMenu()
{
    _graphical.getWindow().draw(_spriteLogo);
    _mainMenu.draw(_graphical.getWindow());

    if (_mainMenu.isValided())
    {
        _mainMenu.resetValided();
        if (_mainMenu.getSelectedIndex() == 0)
        {
            _networkClient->resetGameList();
            _networkClient->getGames();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            handleGetGames();
        }
        else if (_mainMenu.getSelectedIndex() == 1)
        {
            std::cout << "Create " << _mainMenu.getButtonText(1) << "\n";
            _networkClient->createGame(_mainMenu.getButtonText(1));
            _state = GameState::GameLobby;
            _currentGameName = _mainMenu.getButtonText(1);
            handleInitLobby();
        }
        else
        {
            std::string name = _mainMenu.getButtonText(_mainMenu.getSelectedIndex()).substr(0, _mainMenu.getButtonText(_mainMenu.getSelectedIndex()).length() - 6);
            _networkClient->joinGame(name);
            _state = GameState::GameLobby;
            _currentGameName = name;
            handleInitLobby();
        }
    }
}

void RtypeClient::handleGetGames()
{
    _mainMenu.resetButtons();
    _mainMenu.addButton("Refresh", 50, false, true);
    _mainMenu.addButton("Create game: ", 50, true, true);
    for (auto &i : _networkClient->getGameList())
    {
        std::string nbPLayer;
        nbPLayer += std::to_string((int) i.second);
        std::string name = i.first + " - " + nbPLayer + "/4";
        _mainMenu.addButton(name, 50, false, true);
    }
}


void RtypeClient::handleInitLobby()
{
    _lobbyMenu.resetTexts();
    _lobbyMenu.resetButtons();

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    _networkClient->getPlayersInGame(_currentGameName);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    _lobbyMenu.addButton("Start", 80, false, true);

    for (auto &i : _networkClient->getPlayersInGameList())
    {
        _lobbyMenu.addText("- " + i, 30);
    }
    _lobbyMenu.addButton("Refresh", 50, false, true);
}

void RtypeClient::manageLobbyMenu()
{
    _graphical.getWindow().draw(_spriteLogo);
    _lobbyMenu.draw(_graphical.getWindow());

    if (_lobbyMenu.isValided())
    {
        if (_lobbyMenu.getSelectedIndex() == 0)
        {
            _state = GameState::Game;
        }
        else
        {
            handleInitLobby();
        }
    }

}