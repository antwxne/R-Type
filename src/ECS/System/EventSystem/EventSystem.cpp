/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#include <utility>
#include <exception>

#include "EventSystem.hpp"

EventSystem::EventSystem(std::shared_ptr<ComponentManager> components
) : ASystem(components), _callbacksMap(), _currentEvents(ControlGame::NONE), _raisedEvents()
{
}

void EventSystem::subscribeToEvent(const ControlGame &event,
    const Entity &entity, const EventSystem::Callback &callback
) noexcept
{
    std::size_t id;

    entity >> id;
    _callbacksMap[event].emplace_back(std::make_pair(id, callback));
}

void EventSystem::unsubscribeToEvent(const ControlGame &event,
    const Entity &entity
) noexcept
{
    std::size_t id;

    entity >> id;

    try {
        auto elem = _callbacksMap.at(event);
        elem.erase(std::remove_if(elem.begin(), elem.end(),
            [entity](std::pair<std::size_t, Callback> &tmp) {
                std::size_t id;

                entity >> id;
                return tmp.first == id;
            }), elem.end());
    } catch (const std::out_of_range &error) {
        std::cerr << error.what() << std::endl;
    }
}

void EventSystem::update()
{
    if (_currentEvents == ControlGame::NONE) {
        return;
    }
    try {
        for (const auto &callBackVector: _callbacksMap.at(_currentEvents)) {
            callBackVector.second(_componentManager, callBackVector.first,
                std::ref(_raisedEvents));
        }
    } catch (const std::out_of_range &error) {
        std::cerr << error.what() << std::endl;
    }
    _currentEvents = ControlGame::NONE;
}

void EventSystem::setEvents(const ControlGame &event) noexcept
{
    _currentEvents = event;
}

std::shared_ptr<std::vector<ControlGame>> EventSystem::getRaisedEvents() noexcept
{
    std::shared_ptr<std::vector<ControlGame>> dest = std::make_shared<std::vector<ControlGame>>();

    while (!_raisedEvents.empty()) {
        dest->push_back(_raisedEvents.front());
        _raisedEvents.pop();
    }
    return dest;
}

void EventSystem::unsubscribeToAllEvents(const Entity &entity) noexcept
{
    for (auto &it: _callbacksMap) {
        auto &elem = it.second;
        elem.erase(std::remove_if(elem.begin(), elem.end(),
            [=](std::pair<std::size_t, Callback> &tmp) {
                std::size_t id;

                entity >> id;
                return tmp.first == id;
            }), elem.end());
    }
}

bool EventSystem::checkAvailableEntity(std::size_t entity) const
{
    return true;
}
