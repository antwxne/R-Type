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
#include "System/Draw/SfmlDrawSystem.hpp"
#include "System/MoveSystem.hpp"
#include "component.hpp"
#include "Graphical/SfmlEventFactory.hpp"

class ECS {
public:
    ECS();

    Entity createEntity();
    void destroyEntity(const Entity &entity);
    void destroyEntity(const size_t &entity);


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
    std::optional<T> &getComponent(const Entity &entity)
    {
        return _componentManager->getComponent<T>(entity);
    }
    template<typename T>
    SparseArray<T> &getComponentsList()
    {
        return _componentManager->getComponentsList<T>();
    }
    template<typename T>
    const SparseArray<T> &getComponentsList() const
    {
        return _componentManager->getComponentsList<T>();
    }
    ComponentManager::ComponentsMap_t &getComponentMap()
    {
        return _componentManager->getComponentMap();
    }
    template<typename System>
    System &registerSystem()
    {
        return _systemManager->registerSystem<System>();
    }
    template<typename System>
    System &getSystem()
    {
        return _systemManager->getSystem<System>();
    }
    void garbageCollector(std::vector<std::pair<size_t, RaisedEvent>> &raisedEvent);
    void graphicalGarbageCollector();
    const std::shared_ptr<EntityManager> &getEntityManager() const;
    const std::shared_ptr<ComponentManager> &getComponentManager() const;
    const std::unique_ptr<SystemManager> &getSystemManager() const;


private:
    bool isAlive(const std::optional<Life> &lifeComponent) const;
    bool isInScreen(
        const std::optional<Position> &position, const std::optional<Rectangle> &hitbox,const std::optional<Tag> &bullet) const;
    bool isADeadSound(const std::optional<SfmlSound> &sound);
private:
    std::shared_ptr<EntityManager> _entityManager;
    std::shared_ptr<ComponentManager> _componentManager;
    std::unique_ptr<SystemManager> _systemManager;
};

#endif //RTYPE_ECS_HPP