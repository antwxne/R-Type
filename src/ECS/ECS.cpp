/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#include "ECS.hpp"
#include "ECS/System/EventSystem/EventSystem.hpp"
#include "ECS/component.hpp"

Entity ECS::createEntity()
{
    return _entityManager->create();
}

void ECS::destroyEntity(const Entity &entity)
{
    _systemManager->getSystem<Event_n::EventSystem>().unsubscribeToAllEvents(
        entity);
    _componentManager->entityDestroyed(entity);
    _entityManager->destroy(entity);
}

void ECS::destroyEntity(std::size_t entity)
{
    destroyEntity(Entity(entity));
}

ECS::ECS()
{
    _entityManager = std::make_unique<EntityManager>();
    _componentManager = std::make_shared<ComponentManager>();
    _systemManager = std::make_unique<SystemManager>();
}

void ECS::garbageCollector()
{
    const auto &lifes = _componentManager->getComponentsList<Life>();
    const auto &positions = _componentManager->getComponentsList<Position>();
    const auto &hitboxes = _componentManager->getComponentsList<Rectangle>();
    //const auto &bullets = _componentManager->getComponentsList<Bullet>();
    for (std::size_t i = 0; i < MAX_ENTITIES; ++i) {
        if (!isAlive(lifes[i]) || !isInScreen(positions[i], hitboxes[i])) {
            destroyEntity(i);
        }
    }
}

bool ECS::isAlive(const std::optional<Life> &lifeComponent) const
{
    if (!lifeComponent.has_value()) {
        return false;
    }
    return lifeComponent.value().health > 0;
}

bool ECS::isInScreen(
    const std::optional<Position> &position, const std::optional<Rectangle> &hitbox) const //, const std::optional<Bullet> &bullet) const
{
    if (!position.has_value() || !hitbox.has_value()) { //|| !bullet.has_value()
        return false;
    }
    std::pair<float, float> windowSizeMax = {2000, 1200};
    std::pair<float, float> windowSizeMin = {-200, -200};

    return position.value().x < windowSizeMin.first || position.value().y < windowSizeMin.second ||
        position.value().x + static_cast<float>(hitbox.value().width) > windowSizeMax.first ||
        position.value().y + static_cast<float>(hitbox.value().height) > windowSizeMax.second;
}


