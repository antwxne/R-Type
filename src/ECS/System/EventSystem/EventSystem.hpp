/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#ifndef RTYPE_EVENTSYSTEM_HPP
#define RTYPE_EVENTSYSTEM_HPP

#include <unordered_map>
#include <functional>
#include <memory>
#include <vector>
#include <queue>

#include "ECS/System/ASystem.hpp"
#include "Graphical/SfmlEventFactory.hpp"
#include "ECS/Entity/EntityManager.hpp"

class EventSystem : public ASystem {
public:
    using Callback = std::function<void(
        const std::shared_ptr<ComponentManager> &componentManager,
        const std::size_t &entity,
        const std::shared_ptr<EntityManager> &entityManager,
        std::vector<RaisedEvent> &raisedEvents
    )>;
    using CallbackMap = std::unordered_map<size_t, std::vector<std::pair<ControlGame ,Callback>>>;
public:
    EventSystem(const std::shared_ptr<ComponentManager> &components,
        const std::shared_ptr<EntityManager> &entityManager
    );
    ~EventSystem() = default;

    void subscribeToEvent(const ControlGame &event, const Entity &entity,
        const Callback &callback
    ) noexcept;
    void unsubscribeToEvent(const ControlGame &event, const Entity &entity
    ) noexcept;
    void update() override;
    void setEvents(const size_t &entity, ControlGame &events) noexcept;
    void unsubscribeToAllEvents(const Entity &entity) noexcept;
    const std::vector<RaisedEvent> &getRaisedEvents() const noexcept;
    void clearEvents();
    void clearRaisedEvents();

private:
    bool checkAvailableEntity(std::size_t entity) const override;
private:
    CallbackMap _callbacksMap;

    std::unordered_map<size_t, std::vector<ControlGame>> _currentEvents;
    std::vector<RaisedEvent> _raisedEvents;
};

#endif //RTYPE_EVENTSYSTEM_HPP
