/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlEventFactory
*/

#include "SfmlEventFactory.hpp"

SfmlEventFactory::SfmlEventFactory()
{
}

SfmlEventFactory::~SfmlEventFactory()
{
}

ControlGame getEventType(const sf::Event &event)
{
    std::map<sf::Keyboard::Key, ControlGame> eventType( {
    {sf::Keyboard::Key::Up, ControlGame::UP},
    {sf::Keyboard::Key::Down, ControlGame::DOWN},
    {sf::Keyboard::Key::Left, ControlGame::LEFT},
    {sf::Keyboard::Key::Right, ControlGame::RIGHT},
    {sf::Keyboard::Key::Escape, ControlGame::ESCAPE},
    {sf::Keyboard::Key::Space, ControlGame::SPACE},
    {sf::Keyboard::Key::Delete, ControlGame::DELETE}
    });

    if (eventType.find(static_cast<sf::Keyboard::Key>(event.type)) != eventType.end())
    {
    return eventType[static_cast<sf::Keyboard::Key>(event.type)];
    }
    else if (event.type == sf::Event::TextEntered)
    {
        if (event.text.unicode < 128)
            return ControlGame::CHARPRESSED;
    }
    else
    {
        if (event.type == sf::Event::EventType::Closed)
            return ControlGame::QUIT;
    }
    return ControlGame::NONE;
}

std::string getTextEntered(const sf::Event &event)
{
    if (event.type == sf::Event::TextEntered)
    {
        if (event.text.unicode < 128)
        {
            return std::string(1, static_cast<char>(event.text.unicode));
        }
    }
    return "";
}
