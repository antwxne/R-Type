/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-RtypeClient-thomas1.tricaud
** File description:
** RtypeClient
*/

#include "RtypeClient.hpp"

RtypeClient::RtypeClient() : _state(GameState::Game)
{
    _graphical = std::make_shared<SfmlDisplay>();
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
}

void RtypeClient::start()
{
    _ecs.registerComponent<Position>();
    _ecs.registerComponent<Speed>();
    _ecs.registerComponent<Acceleration>();
    _ecs.registerComponent<Texture>();
    _ecs.registerComponent<Scale>();
    _ecs.registerComponent<Rotate>();
    _ecs.registerComponent<Color>();
    _ecs.registerComponent<SfmlSprite>();

    PlayerEntity _pe({150, 50}, {ColorType::None});
    _pe.create(_ecs);

    auto &draw = _ecs.registerSystem<SfmlDrawSystem>();
    _ecs.registerSystem<MoveSystem>();
    draw.setDisplay(_graphical);
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
        _graphical->display();
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
            /* code */
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
            /* code */
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
        /* code */
        break;
    case GameState::GameLobby:
        /* code */
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
    _connectMenu.draw(*_graphical->getWindow());
}

void RtypeClient::manageGame()
{
    _ecs.getSystem<SfmlDrawSystem>().draw(0);
    //_ecs.getSystem<MoveSystem>().update();
}