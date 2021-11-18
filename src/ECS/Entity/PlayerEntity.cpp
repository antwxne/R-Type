/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** PlayerEntity
*/

#include "PlayerEntity.hpp"
#include "ECS/component.hpp"

PlayerEntity::PlayerEntity(const Position &pos,  ColorType color): IEntityRegister()
{
    _pos = pos;
    _color = color;
}

PlayerEntity::~PlayerEntity()
{
}

void PlayerEntity::create(ECS &ecs)
{
    _entity = ecs.createEntity();

    _textureRect = {0,0, 132, 64};

    ecs.subToComponent(_entity, Rotate{0});
    ecs.subToComponent(_entity, _pos);
    ecs.subToComponent(_entity, Tag{{TagType::PLAYER}});
    ecs.subToComponent(_entity, Collision{true});
    ecs.subToComponent(_entity, Texture{TextureType::Player});
    ecs.subToComponent(_entity, Scale{1, 1});
    ecs.subToComponent(_entity, Color{_color});

    std::shared_ptr<sf::Sprite> sprite = std::make_shared<sf::Sprite>();
    sf::Clock clock;

    sprite->setTextureRect(_textureRect);
    ecs.subToComponent(_entity, Firerate{3, clock});
    ecs.subToComponent(_entity, SfmlSprite{sprite, _textureRect, 4, 0, 1});
    ecs.subToComponent(_entity, Speed{10});
    ecs.subToComponent(_entity, Acceleration{1, 1});
    ecs.subToComponent(_entity, Rectangle{_textureRect.width, _textureRect.height});
}
