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
    ASystem(std::shared_ptr<ComponentManager> components);
    bool checkAvailableEntity(const size_t entity);

    virtual void update() = 0;
protected:
    std::shared_ptr<ComponentManager> _componentManager;
    std::vector<std::string> _usedComponents;
};

#endif //RTYPE_ASYSTEM_HPP
