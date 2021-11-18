/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#ifndef RTYPE_SYSTEMMANAGER_HPP
#define RTYPE_SYSTEMMANAGER_HPP

#include <memory>
#include <unordered_map>
#include <any>
#include <map>

#include "ASystem.hpp"
#include "ECS/Component/ComponentManager.hpp"
#include "SparseArray/SparseArray.hpp"

class SystemManager {
public:
    using SystemsMap_t = std::unordered_map<std::string, std::any>;

public:

    SystemManager(const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManager);

    template<typename System>
    System &registerSystem()
    {
        _systemsMap.emplace(typeid(System).name(),
            System(_componentManager, _entityManager));
        return std::any_cast<System &>(_systemsMap[typeid(System).name()]);
    }

    template<typename System>
    System &getSystem()
    {
        return std::any_cast<System &>(_systemsMap.at(typeid(System).name()));
    }

private:
    SystemsMap_t _systemsMap;
    std::shared_ptr<ComponentManager> _componentManager;
    std::shared_ptr<EntityManager> _entityManager;
};

#endif //RTYPE_SYSTEMMANAGER_HPP
