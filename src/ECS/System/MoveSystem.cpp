/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** MoveSystem
*/

#include "MoveSystem.hpp"
#include "../Component/Speed.hpp"
#include "../Component/Acceleration.hpp"
#include "../Component/Transform/Position.hpp"

MoveSystem::MoveSystem(std::shared_ptr<ComponentManager> components) : ASystem(components)
{
    _usedComponents.push_back(typeid(Speed).name());
    _usedComponents.push_back(typeid(Acceleration).name());
    _usedComponents.push_back(typeid(Position).name());
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
        auto &acceleration = _componentManager->getComponent<Acceleration>(i).value();

        position.x += acceleration.x * speed.speed;
        position.y += acceleration.y * speed.speed;
    }
}