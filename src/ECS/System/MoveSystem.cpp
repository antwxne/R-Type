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
#include "utils.hpp"

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
    const auto &entities = _entityManager->getCurrentEntities();
    std::size_t id;

    for (const auto &entity : entities) {
        entity >> id;
        if (!checkAvailableEntity(id))
            continue;
        auto &position = positions[entity].value();
        auto &speed = speeds[entity].value();
        auto &acceleration = accelerations[entity].value();
        const auto &tag = _componentManager->getComponent<Tag>(id);

        if (tag.has_value() && contains<TagType>(tag.value().type, TagType::PLAYER) && !contains<TagType>(tag.value().type, TagType::BULLET)) {
            if (position.x + acceleration.x * speed.speed >= 1820) {
                acceleration.x = 0;
                continue;
            }
            if (position.y + acceleration.y * speed.speed >= 1020) {
                acceleration.y = 0;
                continue;
            }

            if (position.x + acceleration.x * speed.speed <= 0) {
                acceleration.x = 0;
                continue;
            }
            if (position.y + acceleration.y * speed.speed <= 0) {
                acceleration.y = 0;
                continue;
            }
        }
        position.x += acceleration.x * (speed.speed > 0 ? speed.speed : 0);
        position.y += acceleration.y * (speed.speed > 0 ? speed.speed : 0);
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

    return speed[entity].has_value() && acceleration[entity].has_value() &&
        position[entity].has_value();
}
