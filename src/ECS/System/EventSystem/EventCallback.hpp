/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#ifndef RTYPE_EVENTCALLBACK_HPP
#define RTYPE_EVENTCALLBACK_HPP

#include "EventSystem.hpp"

static void PLOP(std::shared_ptr<ComponentManager> componentManager, const std::size_t &entity,
    std::queue<Event_n::Events_e> &raisedEvents)
{
    std::cout << "PLOP" << std::endl;
}


class EventCallback {
public:
    static void changeAccelerationUP(std::shared_ptr<ComponentManager> componentManager, const std::size_t &entity,
    std::queue<Event_n::Event_s> &raisedEvents);
    static void changeAccelerationDOWN(std::shared_ptr<ComponentManager> componentManager, const std::size_t &entity,
        std::queue<Event_n::Event_s> &raisedEvents);
    static void changeAccelerationLEFT(std::shared_ptr<ComponentManager> componentManager, const std::size_t &entity,
        std::queue<Event_n::Event_s> &raisedEvents);
    static void changeAccelerationRIGHT(std::shared_ptr<ComponentManager> componentManager, const std::size_t &entity,
        std::queue<Event_n::Event_s> &raisedEvents);
};

#endif //RTYPE_EVENTCALLBACK_HPP
