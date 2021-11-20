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

void BulletEntity::create(
    const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManager)
{
    _entity = entityManager->create();

    _rect = {0, 0, 110, 25};

    if (_isBulletFriend) {
        componentManager->subToComponent(_entity, Rotate{0});
        componentManager->subToComponent(_entity, Acceleration{1, 0});
        componentManager->subToComponent(_entity, Tag{{TagType::PLAYER, TagType::BULLET}});
    } else {
        componentManager->subToComponent(_entity, Rotate{180});
        componentManager->subToComponent(_entity, Acceleration{-1, 0});
        componentManager->subToComponent(_entity, Tag{{TagType::ENNEMY, TagType::BULLET}});
    }
    componentManager->subToComponent(_entity, _pos);
    componentManager->subToComponent(_entity, Texture{TextureType::Bullet});
    componentManager->subToComponent(_entity, Color{ColorType::Red});
    componentManager->subToComponent(_entity, Scale{1.5, 1.5});

    std::shared_ptr<sf::Sprite> sprite = std::make_shared<sf::Sprite>();

    sprite->setTextureRect(_rect);

    componentManager->subToComponent(_entity, SfmlSprite{sprite, _rect, 0, 0, 0});
    componentManager->subToComponent(_entity, Speed{10});
    componentManager->subToComponent(_entity, Life{1});
    componentManager->subToComponent(_entity, Collision{true});
    componentManager->subToComponent(_entity, Rectangle{_rect.width, _rect.height});
}