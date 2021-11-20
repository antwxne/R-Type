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
#include "ECS/Component/Tag.hpp"
#include "ECS/Component/MoveClock.hpp"
#include "utils.hpp"

typedef std::chrono::high_resolution_clock Clock;

MoveSystem::MoveSystem(const std::shared_ptr<ComponentManager> &components, const std::shared_ptr<EntityManager> &entityManager) : ASystem(
    components, entityManager)
{
}

MoveSystem::~MoveSystem()
{
}

void MoveSystem::update()
{
    auto &positions = _componentManager->getComponentsList<Position>();
    auto &speeds = _componentManager->getComponentsList<Speed>();
    auto &accelerations = _componentManager->getComponentsList<Acceleration>();
    auto &moves = _componentManager->getComponentsList<MoveClock>();
    const auto &entities = _entityManager->getCurrentEntities();
    std::size_t id;

    for (const auto &entity : entities) {
        entity >> id;
        if (!checkAvailableEntity(id))
            continue;

        
        auto &position = positions[entity].value();
        auto &speed = speeds[entity].value();
        auto &acceleration = accelerations[entity].value();
        auto &move = moves[entity].value();

        auto delay = std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - move.clock).count();
        if (delay < move.elapsed)
            return;
        
        move.clock = Clock::now();

        position.x += acceleration.x * (speed.speed > 0 ? speed.speed : 0);
        position.y += acceleration.y * (speed.speed > 0 ? speed.speed : 0);
        const auto &tag = _componentManager->getComponent<Tag>(id);
        if (tag.has_value() && contains<TagType>(tag.value().type, TagType::PLAYER) && !contains<TagType>(tag.value().type, TagType::BULLET)) {
            speed.speed = speed.speed > 0 ? speed.speed - 0.2f : 0;
        }
    }
}

bool MoveSystem::checkAvailableEntity(const size_t entity) const
{
    const auto &speed = _componentManager->getComponentsList<Speed>();
    const auto &acceleration = _componentManager->getComponentsList<Acceleration>();
    const auto &position = _componentManager->getComponentsList<Position>();
    const auto &move = _componentManager->getComponentsList<MoveClock>();

    return speed[entity].has_value() && acceleration[entity].has_value() &&
        position[entity].has_value() && move[entity].has_value();
}
