/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#include <utility>

#include "EventSystem.hpp"

EventSystem::EventSystem(const std::shared_ptr<ComponentManager> &components,
    const std::shared_ptr<EntityManager> &entityManager
) : ASystem(components, entityManager), _callbacksMap(), _currentEvents(),
    _raisedEvents()
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
    try {
        for (const auto &currentEvent: _currentEvents) {
            for (const auto &callBackVector: _callbacksMap.at(currentEvent)) {
                callBackVector.second(_componentManager, callBackVector.first,
                    _entityManager, std::ref(_raisedEvents));
            }
        }
    } catch (const std::out_of_range &error) {
        std::cerr << error.what() << std::endl;
    }
    _currentEvents.clear();
}


void EventSystem::setEvents(std::vector<ControlGame> &events) noexcept
{
    for (const auto &event: events)
        _currentEvents.push_back(event);
    events.clear();
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

const std::vector<RaisedEvent> &EventSystem::getRaisedEvents() const noexcept
{
    return _raisedEvents;
}

void EventSystem::clearEvents()
{
    _currentEvents.clear();
}

void EventSystem::clearRaisedEvents()
{
    _raisedEvents.clear();
}
