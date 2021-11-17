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

#include "ECS/Entity/Entity.hpp"
#include "ECS/System/ASystem.hpp"
#include "Graphical/SfmlEventFactory.hpp"

class EventSystem : public ASystem {
public:
    using Callback = std::function<void(
        std::shared_ptr<ComponentManager>, const std::size_t &,
        std::queue<ControlGame> &)>;
    using CallbackMap = std::unordered_map<ControlGame, std::vector<std::pair<std::size_t, Callback>>>;
public:
    EventSystem(std::shared_ptr<ComponentManager> components);
    ~EventSystem() = default;

    void subscribeToEvent(const ControlGame &event, const Entity &entity,
         const Callback &callback
    ) noexcept;
    void unsubscribeToEvent(const ControlGame &event, const Entity &entity) noexcept;
    void update() override;
    void setEvents(const ControlGame &events) noexcept;
    std::shared_ptr<std::vector<ControlGame>> getRaisedEvents() noexcept;
    void unsubscribeToAllEvents(const Entity &entity) noexcept;
private:
    bool checkAvailableEntity(std::size_t entity) const override;
private:
    CallbackMap _callbacksMap;
    ControlGame _currentEvents;
    std::queue<ControlGame> _raisedEvents;
};

#endif //RTYPE_EVENTSYSTEM_HPP
