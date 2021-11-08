/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#ifndef RTYPE_COMPONENTMANAGER_HPP
#define RTYPE_COMPONENTMANAGER_HPP

#include <unordered_map>
#include <memory>

#include "SparseArray/SparseArray.hpp"
#include "Component/IComponent.hpp"

class ComponentManager {
public:
    using ComponentsMap_t = std::unordered_map<std::type_info, std::shared_ptr<SparseArray<IComponent>>>;
    template<typename T>
    void registerComponent()
    {
        _componentsMap.emplace(typeid(T), std::make_shared<SparseArray<T>>(SparseArray<T>(MAX_ENTITIES)));
    }

    template<typename T>
    void removeComponent(const Entity &entity)
    {
        _componentsMap.at(typeid(T))->deleteData(entity);
    }

    template<typename T>
    T &getComponent(const Entity &entity)
    {
        return _componentsMap.at(typeid(T))->getData(entity);
    }

    template<typename T>
    const T &getComponent(const Entity &entity) const
    {
        return _componentsMap.at(typeid(T))->getData(entity);
    }
    template<typename T>
    std::shared_ptr<SparseArray<IComponent>> &getComponentsList()
    {
        return _componentsMap.at(typeid(T));
    }
    template<typename T>
    const std::shared_ptr<SparseArray<IComponent>> &getComponentsList() const
    {
        return _componentsMap.at(typeid(T));
    }
    std::shared_ptr<ComponentsMap_t> &getComponentMap()
    {
        return std::make_shared<ComponentsMap_t>(_componentsMap);
    }

    void entityDestroyed(const Entity &entity)
    {
        for (auto &elem : _componentsMap) {
            elem.second->entityDestroyed(entity);
        }
    }

private:
    ComponentsMap_t _componentsMap;
};

#endif //RTYPE_COMPONENTMANAGER_HPP
