/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** BulletEntity
*/

#include "BulletEntity.hpp"
#include "../Component/Tag.hpp"

BulletEntity::BulletEntity(const Position &pos, const bool isBulletFriend): IEntityRegister()
{
    _pos = pos;
    _isBulletFriend = isBulletFriend;
}

BulletEntity::~BulletEntity()
{
}

void BulletEntity::create(ECS &ecs)
{
    _entity = ecs.createEntity();

    _rect = {0, 0, 110, 25};

    if (_isBulletFriend) {
        ecs.subToComponent(_entity, Rotate{0});
        ecs.subToComponent(_entity, Acceleration{1, 0});
        ecs.subToComponent(_entity, Tag{{TagType::PLAYER, TagType::BULLET}});
    } else {
        ecs.subToComponent(_entity, Rotate{180});
        ecs.subToComponent(_entity, Acceleration{-1, 0});
        ecs.subToComponent(_entity, Tag{{TagType::ENNEMY, TagType::BULLET}});
    }
    ecs.subToComponent(_entity, _pos);
    ecs.subToComponent(_entity, Texture{TextureType::Bullet});
    ecs.subToComponent(_entity, Color{ColorType::None});
    ecs.subToComponent(_entity, Scale{1.5, 1.5});

    std::shared_ptr<sf::Sprite> sprite = std::make_shared<sf::Sprite>();

    sprite->setTextureRect(_rect);

    ecs.subToComponent(_entity, SfmlSprite{sprite, _rect, 0, 0, 0});
    ecs.subToComponent(_entity, Speed{10});
    ecs.subToComponent(_entity, Collision{true});
    ecs.subToComponent(_entity, Rectangle{_rect.width, _rect.height});
}