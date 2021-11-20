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
#include "ECS/Entity/EntityManager.hpp"

class ASystem {
public:
    ASystem(const std::shared_ptr<ComponentManager> &componentsManager, const std::shared_ptr<EntityManager> &entityManager);
    virtual void update() = 0;

protected:
    virtual bool checkAvailableEntity(size_t entity) const = 0;
protected:
    std::shared_ptr<ComponentManager> _componentManager;
    std::shared_ptr<EntityManager> _entityManager;
};

#endif //RTYPE_ASYSTEM_HPP
