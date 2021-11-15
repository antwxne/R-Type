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

enum ControlGame{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    SPACE,
    ESCAPE,
    DELETE,
    QUIT,
    NONE,
    CHARPRESSED,
};

class SfmlEventFactory {
    public:
        SfmlEventFactory();
        ~SfmlEventFactory();
        ControlGame getEventType(const sf::Event &event) const;
        std::string getTextEntered(const sf::Event &event) const;
};

#endif /* !SFMLEVENTFACTORY_HPP_ */