/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** PlayerEntity
*/

#include "PlayerEntity.hpp"

PlayerEntity::PlayerEntity(const Position &pos, const Color &color)
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

    ecs.subToComponent(player, Rotate{0});
    ecs.subToComponent(player, _pos);
    ecs.subToComponent(player, Texture{TextureType::Player});
    ecs.subToComponent(player, Scale{1, 1});
    ecs.subToComponent(player, _color);
    ecs.subToComponent(player, SfmlSprite{std::make_shared<sf::Sprite>()});
    ecs.subToComponent(player, Speed{1});
    ecs.subToComponent(player, Acceleration{1, 1});
    ecs.subToComponent(player, Rectangle{0, 0,1, 1});

}