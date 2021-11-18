/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** MoveSystem
*/

#include "MoveSystem.hpp"
#include "ECS/Component/Speed.hpp"
#include "ECS/Component/Acceleration.hpp"
#include "ECS/Component/Transform/Position.hpp"

MoveSystem::MoveSystem(const std::shared_ptr<ComponentManager> &components, const std::shared_ptr<EntityManager> &entityManager) : ASystem(
    components, entityManager)
{
}

MoveSystem::~MoveSystem()
{
}

void MoveSystem::update()
{
    for (std::size_t i = 0; i < MAX_ENTITIES; i++) {
        if (!checkAvailableEntity(i))
            continue;
        auto &position = _componentManager->getComponent<Position>(i).value();
        auto &speed = _componentManager->getComponent<Speed>(i).value();
        auto &acceleration = _componentManager->getComponent<Acceleration>(
            i).value();

        position.x += acceleration.x * (int)speed.speed;
        position.y += acceleration.y * (int)speed.speed;
//        acceleration.x = 0;
//        acceleration.y = 0;
    }
}

bool MoveSystem::checkAvailableEntity(const size_t entity) const
{
    const auto &speed = _componentManager->getComponentsList<Speed>();
    const auto &acceleration = _componentManager->getComponentsList<Acceleration>();
    const auto &position = _componentManager->getComponentsList<Position>();

    return speed[entity].has_value() && acceleration[entity].has_value() &&
        position[entity].has_value();
}
