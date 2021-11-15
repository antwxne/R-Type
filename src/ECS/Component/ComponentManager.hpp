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
#include <any>

#include "SparseArray/SparseArray.hpp"


class HasherTypeInfo {
public:
    size_t operator() (const std::type_info & type) const {
        return type.hash_code();
    }
};

class ComponentManager {
public:
    using ComponentsMap_t = std::unordered_map<std::type_info, std::shared_ptr<SparseArray<std::any>>, HasherTypeInfo>;

    ComponentManager();
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
    std::shared_ptr<SparseArray<T>> &getComponentsList()
    {
        return _componentsMap.at(typeid(T));
    }
    template<typename T>
    const std::shared_ptr<SparseArray<T>> &getComponentsList() const
    {
        return _componentsMap.at(typeid(T));
    }
    std::shared_ptr<ComponentsMap_t> getComponentMap()
    {
        return std::make_shared<ComponentsMap_t>(_componentsMap);
    }
    template<typename Component>
    void subToComponent(const Entity &entity, const Component &component)
    {
        _componentsMap.at(typeid(Component))->insertData(entity, component);
    }

    template<typename Component>
    void unsubFromComponent(const Entity &entity)
    {
        _componentsMap.at(typeid(Component))->deleteData(entity);
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
