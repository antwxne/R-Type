/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** BonusEntity
*/

#include "BonusEntity.hpp"

BonusEntity::BonusEntity(const Position &pos, BonusType type) : IEntityRegister()
{
    _pos = pos;
    _type = type;
}

BonusEntity::~BonusEntity()
{
}

void BonusEntity::create(const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManager)
{
    _entity = entityManager->create();

    componentManager->subToComponent(_entity, Rotate{0});
    componentManager->subToComponent(_entity, Acceleration{1, 0});
    componentManager->subToComponent(_entity, Tag{{TagType::POWERUP}});

    std::shared_ptr<sf::Sprite> sprite = std::make_shared<sf::Sprite>();

    sprite->setTextureRect({0, 0, 85, 85});

    componentManager->subToComponent(_entity, MoveClock{7});
    componentManager->subToComponent(_entity, Scale{1, 1});
    componentManager->subToComponent(_entity, SfmlSprite{sprite, {0, 0, 85, 85}, 0, 0, 0});
    componentManager->subToComponent(_entity, Speed{0});
    componentManager->subToComponent(_entity, Life{1});
    componentManager->subToComponent(_entity, Collision{true});
    componentManager->subToComponent(_entity, Rectangle{85, 85});
    componentManager->subToComponent(_entity, Color{ColorType::None});
    componentManager->subToComponent(_entity, _pos);

    if (_type == BonusType::HealBonus)
        componentManager->subToComponent(_entity, Texture{TextureType::HealPowerUp});
    else
    {
        componentManager->subToComponent(_entity, Texture{TextureType::ShotPowerUp});
    }
    componentManager->subToComponent(_entity, Bonus{_type});
}
