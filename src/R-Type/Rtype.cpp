/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Rtype
*/

#include "Rtype.hpp"

Rtype::Rtype() : _state(GameState::ConnectMenu)
{
    _textureLogo.loadFromFile("assets/sprites/r_type_logo.png");
    _spriteLogo.setTexture(_textureLogo);
}

Rtype::~Rtype()
{
}

void Rtype::start()
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
    ecs.subToComponent(player, Color{ColorType::None});
    ecs.subToComponent(player, SfmlSprite{sf::Sprite()});*/
    this->run();
}

void Rtype::run()
{
    while (_graphical.getWindow().isOpen())
    {
        while (_graphical.getWindow().pollEvent(_graphical.getEvent()))
        {
            if (_graphical.getEvent().type == sf::Event::Closed)
                _graphical.getWindow().close();
        }
        _graphical.clear();
        _parallax.update();
        _parallax.draw(_graphical.getWindow());
        this->manageState();
        _graphical.display();
    }
}

void Rtype::manageState()
{
    switch (_state)
    {
    case GameState::ConnectMenu:
        this->manageConnectMenu();
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

void Rtype::manageConnectMenu()
{
    _graphical.getWindow().draw(_spriteLogo);
}