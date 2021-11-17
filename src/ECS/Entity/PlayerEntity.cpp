/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** PlayerEntity
*/

#include "PlayerEntity.hpp"

PlayerEntity::PlayerEntity(const Position &pos,  ColorType color)
{
    _pos = pos;
    _color = color;
}

PlayerEntity::~PlayerEntity()
{
}

void PlayerEntity::create(ECS &ecs)
{
    Entity player = ecs.createEntity();

    _textureRect = {0,0, 132, 64};

    ecs.subToComponent(player, Rotate{0});
    ecs.subToComponent(player, _pos);
    ecs.subToComponent(player, Texture{TextureType::Player});
    ecs.subToComponent(player, Scale{1, 1});
    ecs.subToComponent(player, Color{_color});

    std::shared_ptr<sf::Sprite> sprite = std::make_shared<sf::Sprite>();

    sprite->setTextureRect(_textureRect);

    ecs.subToComponent(player, SfmlSprite{sprite, _textureRect, 5, 0});
    ecs.subToComponent(player, Speed{1});
    ecs.subToComponent(player, Acceleration{1, 1});
}