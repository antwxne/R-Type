/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** BulletEntity
*/

#include "BulletEntity.hpp"
#include "../Component/Tag.hpp"

BulletEntity::BulletEntity(const Position &pos, const bool isBulletFriend)
{
    _pos = pos;
    _isBulletFriend = isBulletFriend;
}

BulletEntity::~BulletEntity()
{
}

void BulletEntity::create(ECS &ecs)
{
    Entity bullet = ecs.createEntity();

    _rect = {0, 0, 110, 25};

    if (_isBulletFriend) {
        ecs.subToComponent(bullet, Rotate{0});
        ecs.subToComponent(bullet, Acceleration{1, 0});
        ecs.subToComponent(bullet, Tag{{TagType::PLAYER, TagType::BULLET}});
    } else {
        ecs.subToComponent(bullet, Rotate{180});
        ecs.subToComponent(bullet, Acceleration{-1, 0});
        ecs.subToComponent(bullet, Tag{{TagType::ENNEMY, TagType::BULLET}});
    }
    ecs.subToComponent(bullet, _pos);
    ecs.subToComponent(bullet, Texture{TextureType::Bullet});
    ecs.subToComponent(bullet, Color{ColorType::None});
    ecs.subToComponent(bullet, Scale{1.5, 1.5});

    std::shared_ptr<sf::Sprite> sprite = std::make_shared<sf::Sprite>();

    sprite->setTextureRect(_rect);

    ecs.subToComponent(bullet, SfmlSprite{sprite, _rect, 0, 0});
    ecs.subToComponent(bullet, Speed{1});
    ecs.subToComponent(bullet, Colission{true});
    ecs.subToComponent(bullet, Hitbox{100, 100});
}