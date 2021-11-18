/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#include "ASystem.hpp"

#include "ECS/component.hpp"

ASystem::ASystem(const std::shared_ptr<ComponentManager> &componentsManager, const std::shared_ptr<EntityManager> &entityManager): _componentManager(componentsManager), _entityManager(entityManager)
{

}