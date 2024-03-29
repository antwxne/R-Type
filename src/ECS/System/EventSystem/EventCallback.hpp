/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#ifndef RTYPE_EVENTCALLBACK_HPP
#define RTYPE_EVENTCALLBACK_HPP

#include "EventSystem.hpp"
#include "ECS/Entity/EntityManager.hpp"
#include "ECS/Component/ComponentManager.hpp"

class EventCallback {
public:
    static void changeAccelerationUP(
        const std::shared_ptr<ComponentManager> &componentManager,
        const std::size_t &entity, const std::shared_ptr<EntityManager> &entityManager,
        std::vector<RaisedEvent> &raisedEvents
    );
    static void changeAccelerationDOWN(
        const std::shared_ptr<ComponentManager> &componentManager,
        const std::size_t &entity, const std::shared_ptr<EntityManager> &entityManager,
        std::vector<RaisedEvent> &raisedEvents
    );
    static void changeAccelerationLEFT(
        const std::shared_ptr<ComponentManager> &componentManager,
        const std::size_t &entity, const std::shared_ptr<EntityManager> &entityManager,
        std::vector<RaisedEvent> &raisedEvents
    );
    static void changeAccelerationRIGHT(
        const std::shared_ptr<ComponentManager> &componentManager,
        const std::size_t &entity, const std::shared_ptr<EntityManager> &entityManager,
        std::vector<RaisedEvent> &raisedEvents
    );
    static void shoot(const std::shared_ptr<ComponentManager> &componentManager,
        const std::size_t &entity, const std::shared_ptr<EntityManager> &entityManager,
        std::vector<RaisedEvent> &raisedEvents
    );
};

#endif //RTYPE_EVENTCALLBACK_HPP
