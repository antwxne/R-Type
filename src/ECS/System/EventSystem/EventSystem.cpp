/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#include <utility>
#include <exception>

#include "EventSystem.hpp"

Event_n::EventSystem::EventSystem(
    std::shared_ptr<ComponentManager> components
) : ASystem(components), _callbacksMap(), _currentEvents(100), _raisedEvents()
{
}

void Event_n::EventSystem::subscribeToEvent(const Event &event,
    const Entity &entity, const Event_n::EventSystem::Callback &callback
) noexcept
{
    std::size_t id;

    entity >> id;
    _callbacksMap[event].emplace_back(std::make_pair(id, callback));
}

void Event_n::EventSystem::unsubscribeToEvent(const Event_n::Event &event,
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

void Event_n::EventSystem::update()
{
    for (const auto &event: _currentEvents) {
        try {
            for (const auto &callBackVector: _callbacksMap.at(event)) {
                callBackVector.second(_componentManager, callBackVector.first,
                    std::ref(_raisedEvents));
            }
        } catch (const std::out_of_range &error) {
            std::cerr << error.what() << std::endl;
        }
    }
}

void Event_n::EventSystem::setEvents(const std::vector<Event_n::Event> &events) noexcept
{
    _currentEvents = events;
}

std::shared_ptr<std::vector<Event_n::Event>> Event_n::EventSystem::getRaisedEvents() noexcept
{
    std::shared_ptr<std::vector<Event_n::Event>> dest = std::make_shared<std::vector<Event_n::Event>>();

    while (!_raisedEvents.empty()) {
        dest->push_back(_raisedEvents.front());
        _raisedEvents.pop();
    }
    return dest;
}

Event_n::Event::Event(Event_n::State_e newState, Event_n::Events_e newEvent)
    : state(newState), event(newEvent)
{
}

std::size_t Event_n::Event::operator()(const Event_n::Event &evt) const
{
    union convertToHash {
        std::size_t hash;
        uint32_t var[2];
    };
    convertToHash conv;

    conv.var[0] = evt.state;
    conv.var[1] = evt.event;
    return conv.hash;
}

bool Event_n::Event::operator==(const Event_n::Event &other) const
{
    return this->event == other.event && this->state == other.state;
}
