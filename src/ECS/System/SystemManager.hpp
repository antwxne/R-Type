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

#include "ASystem.hpp"
#include "ECS/Component/ComponentManager.hpp"
#include "SparseArray/SparseArray.hpp"

class HasherTypeSystemInfo {
public:
    size_t operator() (const std::type_info & type) const {
        return type.hash_code();
    }
};

class SystemManager {
public:
    using SystemsMap_t = std::unordered_map<std::type_info, std::shared_ptr<std::any>, HasherTypeSystemInfo>;

public:

    SystemManager();

    template<typename System>
    std::shared_ptr<System> registerSystem(std::shared_ptr<ComponentManager::ComponentsMap_t> components)
    {
        auto plop = std::make_shared<System>(components);

        _systemsMap.emplace(typeid(System), plop);
        return plop;
    }
    template<typename System>
    std::shared_ptr<System> getSystem()
    {
        return _systemsMap.at(typeid(System));
    }
private:
    SystemsMap_t _systemsMap;
};

#endif //RTYPE_SYSTEMMANAGER_HPP
