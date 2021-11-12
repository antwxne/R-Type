/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#ifndef RTYPE_ASYSTEM_HPP
#define RTYPE_ASYSTEM_HPP

#include <memory>
#include <any>

#include "SparseArray/SparseArray.hpp"
#include "ECS/Component/ComponentManager.hpp"

class ASystem {
public:
    ASystem(std::shared_ptr<ComponentManager::ComponentsMap_t> &components);
    bool checkAvaiableEntity(const size_t entity);

    virtual void update() = 0;
protected:
    std::shared_ptr<ComponentManager::ComponentsMap_t> _components;
    std::vector<std::reference_wrapper<const std::type_info>> _usedComponents;
};

#endif //RTYPE_ASYSTEM_HPP
