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
    virtual void update() = 0;

protected:
    virtual bool checkAvailableEntity(size_t entity) const = 0;
protected:
    std::shared_ptr<ComponentManager> _componentManager;
};

#endif //RTYPE_ASYSTEM_HPP
