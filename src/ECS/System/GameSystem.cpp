/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** GameSystem
*/

#include "GameSystem.hpp"

GameSystem::GameSystem(const std::shared_ptr<ComponentManager> &components, const std::shared_ptr<EntityManager> &entityManager) : ASystem(components, entityManager)
{
}

GameSystem::~GameSystem()
{
}
