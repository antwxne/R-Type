/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlEventFactory
*/

#ifndef SFMLEVENTFACTORY_HPP_
#define SFMLEVENTFACTORY_HPP_

#include "SFML/Graphics.hpp"
#include <map>
#include <string>

#ifdef _win32

enum ControlGame: int {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    SPACE,
    ESCAPE,
    ENTER,
    DELETE,
    NONE,
};
enum RaisedEvent: int {
    SHOT,
    ENTITY_DEAD
};
#else

enum ControlGame {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    SPACE,
    ESCAPE,
    ENTER,
    DELETE,
    D,
    NONE,
};

enum RaisedEvent {
    SHOT,
    ENTITY_DEAD
};

#endif

class SfmlEventFactory {
public:
    SfmlEventFactory();
    ~SfmlEventFactory();
    ControlGame getEventType(const sf::Event &event) const;
    std::string getTextEntered(const sf::Event &event) const;
private:
    static const std::map<sf::Keyboard::Key, ControlGame> eventType;
};

#endif /* !SFMLEVENTFACTORY_HPP_ */
