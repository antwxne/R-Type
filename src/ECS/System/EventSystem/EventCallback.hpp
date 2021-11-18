/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#ifndef RTYPE_EVENTCALLBACK_HPP
#define RTYPE_EVENTCALLBACK_HPP

#include "EventSystem.hpp"

class EventCallback {
public:
    static void changeAccelerationUP(std::shared_ptr<ComponentManager> componentManager, const std::size_t &entity,
    std::queue<ControlGame> &raisedEvents);
    static void changeAccelerationDOWN(std::shared_ptr<ComponentManager> componentManager, const std::size_t &entity,
        std::queue<ControlGame> &raisedEvents);
    static void changeAccelerationLEFT(std::shared_ptr<ComponentManager> componentManager, const std::size_t &entity,
        std::queue<ControlGame> &raisedEvents);
    static void changeAccelerationRIGHT(std::shared_ptr<ComponentManager> componentManager, const std::size_t &entity,
        std::queue<ControlGame> &raisedEvents);
    static void shoot(std::shared_ptr<ComponentManager> componentManager, const std::size_t &entity,
        std::queue<ControlGame> &raisedEvents);
};

#endif //RTYPE_EVENTCALLBACK_HPP
