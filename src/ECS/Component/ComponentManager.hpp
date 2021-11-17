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
#include <map>

#include "SparseArray/SparseArray.hpp"

class ComponentManager {
public:
    using ComponentsMap_t = std::map<std::string, std::any>;

    ComponentManager() = default;
    template<typename T>
    void registerComponent()
    {
        _componentsMap.emplace(typeid(T).name(), std::make_any<SparseArray<T>>(MAX_ENTITIES));
    }

    template<typename T>
    void removeComponent(const Entity &entity)
    {
        std::any_cast<SparseArray<T> &>(_componentsMap.at(typeid(T).name())).deleteData(entity);
    }


    template<typename T>
    std::optional<T> &getComponent(const Entity &entity)
    {
        return std::any_cast<SparseArray<T> &>(_componentsMap.at(typeid(T).name())).getData(entity);
    }
    template<typename T>
    SparseArray<T> &getComponentsList()
    {
        return std::any_cast<SparseArray<T> &>(_componentsMap.at(typeid(T).name()));
    }
    template<typename T>
    const SparseArray<T> &getComponentsList() const
    {
        return std::any_cast<SparseArray<T> &>(_componentsMap.at(typeid(T).name()));
    }
    ComponentsMap_t &getComponentMap()
    {
        return _componentsMap;
    }
    template<typename Component>
    void subToComponent(const Entity &entity, const Component &component)
    {
        std::any_cast<SparseArray<Component> &>(_componentsMap.at(typeid(Component).name())).insertData(entity, component);
    }

    template<typename Component>
    void unsubFromComponent(const Entity &entity)
    {
        std::any_cast<SparseArray<Component> &>(_componentsMap.at(typeid(Component).name())).deleteData(entity);
    }
    void entityDestroyed(const Entity &entity)
    {
        for (auto &elem : _componentsMap) {
            std::cout << "LA" << std::endl;
            std::any_cast<SparseArray<std::any> &>(elem.second).entityDestroyed(entity);
        }
    }

private:
    ComponentsMap_t _componentsMap;
};

#endif //RTYPE_COMPONENTMANAGER_HPP