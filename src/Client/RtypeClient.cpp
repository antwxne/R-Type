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
}

RtypeClient::~RtypeClient()
{
}

void RtypeClient::initMenu()
{
    _connectMenu.addButton("Name: ", 50, true);
    _connectMenu.addButton("IP: ", 50, true);
    _connectMenu.addButton("Port: ", 50, true);
    _connectMenu.addButton("Connect", 70, false, true);

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
            /* code */
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
            /* code */
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
        /* code */
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

        _networkClient = std::make_shared<Client>();

        try
        {
            std::string sPort = (_connectMenu.getButtonText(2));
            int port = std::stoi(sPort);

            if (_networkClient->tryConnect(_connectMenu.getButtonText(1), 8080))
            {
                _state = GameState::MainMenu;
                _networkThread = std::thread(&Client::start, _networkClient);
                _networkClient->setPlayerName(_connectMenu.getButtonText(0));
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                _networkClient->getGames();
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
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

            _networkClient->createGame(_mainMenu.getButtonText(0));
        }
    }
}

void RtypeClient::handleGetGames()
{
    _mainMenu.resetButtons();
    _mainMenu.addButton("Create game: ", 50, true, true);
    for (auto &i : _networkClient->getGameList())
    {
        std::string nbPLayer;
        nbPLayer += std::to_string((int) i.second);
        std::string name = i.first + " - " + nbPLayer + "/4";
        _mainMenu.addButton(name, 50, false, true);
    }
}