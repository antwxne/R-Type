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

bool ASystem::checkAvaiableEntity(const size_t entity)
{
    for (auto &i : _usedComponents)
    {
        if (_components->at(i)->getData(entity).has_value() == false)
            return false;
    }
    return true;
}