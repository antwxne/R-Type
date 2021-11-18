/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#include "SystemManager.hpp"

SystemManager::SystemManager(
    const std::shared_ptr<ComponentManager> &componentManager,
    const std::shared_ptr<EntityManager> &entityManager
): _componentManager(componentManager), _entityManager(entityManager)
{
}
