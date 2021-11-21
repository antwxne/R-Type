/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** EnemyShootSystem
*/

#include "EnemyShootSystem.hpp"

EnemyShootSystem::EnemyShootSystem(
    const std::shared_ptr<ComponentManager> &components, const std::shared_ptr<EntityManager> &entityManager) : ASystem(components, entityManager)
{
}

EnemyShootSystem::~EnemyShootSystem()
{
}

void EnemyShootSystem::update()
{
    auto &tags = _componentManager->getComponentsList<Tag>();
    auto &positions = _componentManager->getComponentsList<Position>();
    auto &firerates = _componentManager->getComponentsList<Firerate>();
    auto &sprites = _componentManager->getComponentsList<SfmlSprite>();
    const auto &entities = _entityManager->getCurrentEntities();
    std::size_t id;

    for (const auto &entity : entities) {
        entity >> id;
        if (!checkAvailableEntity(id))
            continue;
        Tag &tag = tags[id].value();
        Firerate &firerate = firerates[id].value();
        Position pos = positions[id].value();
        SfmlSprite &sprite = sprites[id].value();
        float elapsed = firerate.clock.getElapsedTime().asSeconds();
        if (contains(tag.type, TagType::ENEMY) && !contains(tag.type, TagType::BULLET)) {
            if (elapsed <= firerate.delay)
                continue;
            pos.x -= 30;
            pos.y += (sprite.textureRect.height / 2) + 50;
            BulletEntity _be(pos, false);
            _be.create(_componentManager, _entityManager);
            firerate.clock.restart();
            return;
        }
    }
}

bool EnemyShootSystem::checkAvailableEntity(std::size_t entity) const
{
    const auto &position = _componentManager->getComponentsList<Position>();
    const auto &tag = _componentManager->getComponentsList<Tag>();
    const auto &firerate = _componentManager->getComponentsList<Firerate>();

    return position[entity].has_value() && tag[entity].has_value() && firerate[entity].has_value();
}