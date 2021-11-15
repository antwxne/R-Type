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

MoveSystem::MoveSystem(std::shared_ptr<ComponentManager::ComponentsMap_t> &components) : ASystem(components)
{
    _usedComponents.push_back(typeid(Speed));
    _usedComponents.push_back(typeid(Acceleration));
    _usedComponents.push_back(typeid(Position));
}

MoveSystem::~MoveSystem()
{
}

void MoveSystem::update()
{
    for (std::size_t i = 0; i < MAX_ENTITIES; i++) {
        if (!checkAvailableEntity(i))
            continue;
        auto &position = std::any_cast<Position&>(_components->at(typeid(Position))->getData(i).value());
        auto &speed = std::any_cast<Speed&>(_components->at(typeid(Speed))->getData(i).value());
        auto &acceleration = std::any_cast<Acceleration&>(_components->at(typeid(Acceleration))->getData(i).value());

        position.x += acceleration.x * speed.speed;
        position.y += acceleration.y * speed.speed;
    }
}