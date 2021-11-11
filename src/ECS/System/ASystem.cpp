/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#include "ASystem.hpp"

ASystem::ASystem(std::shared_ptr<ComponentManager::ComponentsMap_t> &components): _components(std::move(components))
{

}
