/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#include "ECS.hpp"

Entity ECS::createEntity()
{
    return _entityManager->create();
}

void ECS::destroyEntity(const Entity &entity)
{
    _entityManager->destroy(entity);
}

ECS::ECS()
{
    _entityManager = std::make_unique<EntityManager>();
    _componentManager = std::make_shared<ComponentManager>();
    _systemManager = std::make_unique<SystemManager>();
}