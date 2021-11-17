/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#include <iostream>

#include "ECS/component.hpp"
#include "EventCallback.hpp"

void EventCallback::changeAccelerationUP(std::shared_ptr<ComponentManager> componentManager,
    const size_t &entity, std::queue<ControlGame> &raisedEvents
)
{
    std::cout << "GO UP" << std::endl;
    auto &currentAcceleration = componentManager->getComponent<Acceleration>(entity);
    if (!currentAcceleration.has_value()) {
        return;
    }
    currentAcceleration.value().x = 0;
    currentAcceleration.value().y = -1;
}

void EventCallback::changeAccelerationDOWN(
    std::shared_ptr<ComponentManager> componentManager, const size_t &entity,
    std::queue<ControlGame> &raisedEvents
)
{
    auto &currentAcceleration = componentManager->getComponent<Acceleration>(entity);
    if (!currentAcceleration.has_value()) {
        return;
    }
    currentAcceleration.value().x = 0;
    currentAcceleration.value().y = 1;
}

void EventCallback::changeAccelerationLEFT(
    std::shared_ptr<ComponentManager> componentManager, const size_t &entity,
    std::queue<ControlGame> &raisedEvents
)
{
    auto &currentAcceleration = componentManager->getComponent<Acceleration>(entity);
    if (!currentAcceleration.has_value()) {
        return;
    }
    currentAcceleration.value().x = -1;
    currentAcceleration.value().y = 0;

}

void EventCallback::changeAccelerationRIGHT(
    std::shared_ptr<ComponentManager> componentManager, const size_t &entity,
    std::queue<ControlGame> &raisedEvents
)
{
    std::cout << "go right" << std::endl;
    auto &currentAcceleration = componentManager->getComponent<Acceleration>(entity);
    if (!currentAcceleration.has_value()) {
        return;
    }
    std::cout << "go right plop" << std::endl;

    currentAcceleration.value().x = 1;
    currentAcceleration.value().y = 0;
}
