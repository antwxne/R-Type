/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#include "ASystem.hpp"

ASystem::ASystem(std::shared_ptr<ComponentManager> components): _componentManager(std::move(components))
{

}

bool ASystem::checkAvailableEntity(const size_t entity)
{
    auto componentMap = _componentManager->getComponentMap();
    for (const auto &i : _usedComponents)
    {
        if (!std::any_cast<SparseArray<std::any>>(componentMap.at(i)).getData(entity).has_value())
            return false;
    }
    return true;
}