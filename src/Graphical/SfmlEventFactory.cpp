/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlEventFactory
*/

#include "SfmlEventFactory.hpp"


std::map<sf::Keyboard::Key, ControlGame> SfmlEventFactory::eventType =  {
    {sf::Keyboard::Key::Up, ControlGame::UP},
    {sf::Keyboard::Key::Down, ControlGame::DOWN},
    {sf::Keyboard::Key::Left, ControlGame::LEFT},
    {sf::Keyboard::Key::Right, ControlGame::RIGHT},
    {sf::Keyboard::Key::Escape, ControlGame::ESCAPE},
    {sf::Keyboard::Key::Space, ControlGame::SPACE},
    {sf::Keyboard::Key::BackSpace, ControlGame::DELETE}
    };

SfmlEventFactory::SfmlEventFactory()
{
}

SfmlEventFactory::~SfmlEventFactory()
{
}

ControlGame SfmlEventFactory::getEventType(const sf::Event &event) const
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (eventType.find(event.key.code) != eventType.end())
            return eventType[event.key.code];
        else
            return ControlGame::NONE;
    }
    return ControlGame::NONE;
}

std::string SfmlEventFactory::getTextEntered(const sf::Event &event) const
{
    if (event.type == sf::Event::TextEntered)
    {
        if (event.text.unicode < 128 && event.text.unicode != 8)
        {
            return std::string(1, static_cast<char>(event.text.unicode));
        }
    }
    return "";
}
