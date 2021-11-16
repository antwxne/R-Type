/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-RtypeClient-thomas1.tricaud
** File description:
** RtypeClient
*/

#include "RtypeClient.hpp"
#include "ECS/System/EventSystem/EventSystem.hpp"
#include "ECS/System/EventSystem/EventCallback.hpp"

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
    _ecs.registerComponent<Texture>();
    _ecs.registerComponent<Acceleration>();
    _ecs.registerComponent<Scale>();
    _ecs.registerComponent<Rotate>();
    _ecs.registerComponent<Color>();
    _ecs.registerComponent<SfmlSprite>();
    auto &draw = _ecs.registerSystem<SfmlDrawSystem>();
    draw.setDisplay(_graphical);
    Entity player = _ecs.createEntity();

    _ecs.subToComponent(player, Position{50, 50});
    _ecs.subToComponent(player, Texture{TextureType::Player});
    _ecs.subToComponent(player, Scale{1});
    _ecs.subToComponent(player, Color{ColorType::None});
    _ecs.subToComponent(player, SfmlSprite{sf::Sprite()});
    _ecs.subToComponent(player, Acceleration{0, 0});


    auto &evtManager = _ecs.registerSystem<Event_n::EventSystem>();

    // BIND une fonction statique a un evenement
    Event_n::Event_s evt(Event_n::PRESS, Event_n::KEY_UP);
    evtManager.subscribeToEvent(evt, player, std::bind(EventCallback::changeAccelerationUP, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

    // remplir le vecteur d'evenements -> tous les evenements utilisés a cette frame
    std::vector<Event_n::Event_s> tmp = {evt};
    // envoyer les evenements dans le gestionnaire d'evenements
    evtManager.setEvents(tmp);
    // appliquer les evenements de la frame sur les components register
    evtManager.update();
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
        /* code */
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