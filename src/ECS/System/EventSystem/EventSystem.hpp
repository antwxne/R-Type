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

namespace Event_n {

#ifdef __WIN32

enum State_e: int {
    UNDEFINED,
    PRESS,
    RELEASE
};

enum Events_e: int {
    NONE,
    KEY_A,
    KEY_B,
    KEY_C,
    KEY_D,
    KEY_E,
    KEY_F,
    KEY_G,
    KEY_H,
    KEY_I,
    KEY_J,
    KEY_K,
    KEY_L,
    KEY_M,
    KEY_N,
    KEY_O,
    KEY_P,
    KEY_Q,
    KEY_R,
    KEY_S,
    KEY_T,
    KEY_U,
    KEY_V,
    KEY_W,
    KEY_X,
    KEY_Y,
    KEY_Z,
    KEY_SPACE,
    KEY_ENTER,
    KEY_BACKSPACE,
    KEY_ESCAPE,
    KEY_UP,
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_PAGEUP,
    KEY_PAGEDOWN
};
#else

enum State_e {
    UNDEFINED,
    PRESS,
    RELEASE
};

enum Events_e {
    NONE,
    KEY_A,
    KEY_B,
    KEY_C,
    KEY_D,
    KEY_E,
    KEY_F,
    KEY_G,
    KEY_H,
    KEY_I,
    KEY_J,
    KEY_K,
    KEY_L,
    KEY_M,
    KEY_N,
    KEY_O,
    KEY_P,
    KEY_Q,
    KEY_R,
    KEY_S,
    KEY_T,
    KEY_U,
    KEY_V,
    KEY_W,
    KEY_X,
    KEY_Y,
    KEY_Z,
    KEY_SPACE,
    KEY_ENTER,
    KEY_BACKSPACE,
    KEY_ESCAPE,
    KEY_UP,
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_PAGEUP,
    KEY_PAGEDOWN
};
#endif

struct Event {
    Event(State_e newState = UNDEFINED, Events_e newEvent = NONE);
    State_e state;
    Events_e event;

    bool operator==(const Event &other) const;
    std::size_t operator()(const Event &evt) const;
};

class EventSystem : public ASystem {
public:
    using Callback = std::function<void(
        std::shared_ptr<ComponentManager>, const std::size_t &,
        std::queue<Event> &
    )>;
    using CallbackMap = std::unordered_map<Event, std::vector<std::pair<std::size_t, Callback>>, Event>;
public:
    EventSystem(std::shared_ptr<ComponentManager> components);
    ~EventSystem() = default;

    void subscribeToEvent(const Event &event, const Entity &entity,
        const std::function<void(
            std::shared_ptr<ComponentManager>, const size_t &,
            std::queue<Event> &
        )> &callback
    ) noexcept;
    void unsubscribeToEvent(const Event &event, const Entity &entity) noexcept;
    void update() override;
    void setEvents(const std::vector<Event> &events) noexcept;
    std::shared_ptr<std::vector<Event>> getRaisedEvents() noexcept;

private:
    CallbackMap _callbacksMap;
    std::vector<Event> _currentEvents;
    std::queue<Event> _raisedEvents;
};
}
#endif //RTYPE_EVENTSYSTEM_HPP