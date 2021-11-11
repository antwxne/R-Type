/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#ifndef RTYPE_ECS_HPP
#define RTYPE_ECS_HPP

#include <memory>

#include "Entity/EntityManager.hpp"
#include "Component/ComponentManager.hpp"
#include "System/SystemManager.hpp"

class ECS {
public:
    ECS() = default;

    void init() noexcept;

    Entity createEntity();
    void destroyEntity(const Entity &entity);

    template<class Component>
    void registerComponent()
    {
        _componentManager->registerComponent<Component>();
    }
    template<class Component>
    void subToComponent(const Entity &entity, const Component &component)
    {
        _componentManager->subToComponent(entity, component);
    }
    template<class Component>
    void unsubFromComponent(const Entity &entity)
    {
        _componentManager->unsubFromComponent<Component>(entity);
    }
    template<typename T>
    T &getComponent(const Entity &entity)
    {
        return _componentManager->getComponent<T>(entity);
    }
    template<typename T>
    const T &getComponent(const Entity &entity) const
    {
        return _componentManager->getComponent<T>(entity);
    }
    template<typename T>
    std::shared_ptr<SparseArray<T>> &getComponentsList()
    {
        return _componentManager->getComponentsList<T>();
    }
    template<typename T>
    const std::shared_ptr<SparseArray<T>> &getComponentsList() const
    {
        return _componentManager->getComponentsList<T>();
    }
    ComponentManager::ComponentsMap_t &getComponentMap()
    {
        return _componentManager->getComponentMap();
    }

    template<typename System>
    std::shared_ptr<System> getSystem()
    {
        return _systemManager->getSystem<System>();
    }
private:
    std::unique_ptr<EntityManager> _entityManager;
    std::unique_ptr<ComponentManager> _componentManager;
    std::unique_ptr<SystemManager> _systemManager;
};

#endif //RTYPE_ECS_HPP
