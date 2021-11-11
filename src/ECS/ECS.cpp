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