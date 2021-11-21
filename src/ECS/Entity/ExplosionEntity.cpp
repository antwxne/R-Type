/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** ExplosionEntity
*/

#include "ExplosionEntity.hpp"

ExplosionEntity::ExplosionEntity(const Position &pos) : IEntityRegister()
{
    _pos = pos;
}

ExplosionEntity::~ExplosionEntity()
{
}

void ExplosionEntity::create(
    const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManager)
{
    _entity = entityManager->create();
    _textureRect = {0,0, 128, 128};

    componentManager->subToComponent(_entity, Rotate{0});
    componentManager->subToComponent(_entity, _pos);
    componentManager->subToComponent(_entity, Tag{{TagType::EXPLOSION}});
    componentManager->subToComponent(_entity, Collision{true});
    componentManager->subToComponent(_entity, Texture{TextureType::Explosions});
    componentManager->subToComponent(_entity, Scale{1, 1});
    componentManager->subToComponent(_entity, Color{ColorType::None});
    componentManager->subToComponent(_entity, MoveClock{1});
    componentManager->subToComponent(_entity, ExploseClock{1500, std::chrono::high_resolution_clock::now()});
    std::shared_ptr<sf::Sprite> sprite = std::make_shared<sf::Sprite>();

    sprite->setTextureRect(_textureRect);
    componentManager->subToComponent(_entity, SfmlSprite{sprite, _textureRect, 16, 1, 0.1});
    componentManager->subToComponent(_entity, Life{100});
    componentManager->subToComponent(_entity, Rectangle{_textureRect.width, _textureRect.height});
    componentManager->subToComponent(_entity, Speed{0});
    componentManager->subToComponent(_entity, Acceleration{0, 0});
}