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

class SystemManager {
public:
    using SystemsMap_t = std::unordered_map<std::type_info, std::shared_ptr<std::any>>;

public:

    SystemManager();

    template<typename System>
    std::shared_ptr<System> registerSystem(std::shared_ptr<ComponentManager::ComponentsMap_t> &components)
    {
        _systemsMap.emplace(typeid(System), std::make_shared<System>(components));
        return _systemsMap.at(typeid(System));
    }
    template<typename System>
    std::shared_ptr<System> getSystem()
    {
        return (_systemsMap.at(typeid(System)));
    }
private:
    SystemsMap_t _systemsMap;
};

#endif //RTYPE_SYSTEMMANAGER_HPP
