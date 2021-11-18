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
    static void changeAccelerationUP(std::shared_ptr<ComponentManager> componentManager, const std::size_t &entity,
        std::shared_ptr<EntityManager> entityManager);
    static void changeAccelerationDOWN(std::shared_ptr<ComponentManager> componentManager, const std::size_t &entity,
        std::shared_ptr<EntityManager> entityManager);
    static void changeAccelerationLEFT(std::shared_ptr<ComponentManager> componentManager, const std::size_t &entity,
        std::shared_ptr<EntityManager> entityManager);
    static void changeAccelerationRIGHT(std::shared_ptr<ComponentManager> componentManager, const std::size_t &entity,
        std::shared_ptr<EntityManager> entityManager);
    static void shoot(std::shared_ptr<ComponentManager> componentManager, const std::size_t &entity,
        std::shared_ptr<EntityManager> entityManager);
};

#endif //RTYPE_EVENTCALLBACK_HPP
