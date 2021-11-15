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

class HasherTypeSystemInfo {
public:
    size_t operator()(const std::type_info &type) const
    {
        return type.hash_code();
    }
};

class SystemManager {
public:
    using SystemsMap_t = std::unordered_map<std::string, std::any>;

public:

    SystemManager() = default;

    template<typename System>
    System &registerSystem(std::shared_ptr<ComponentManager> componentManager)
    {
        _systemsMap.emplace(typeid(System).name(), System(componentManager));
        return std::any_cast<System &>(_systemsMap[typeid(System).name()]);
    }

    template<typename System>
    System &getSystem()
    {
        return _systemsMap.at(typeid(System).name());
    }

private:
    SystemsMap_t _systemsMap;
};

#endif //RTYPE_SYSTEMMANAGER_HPP
