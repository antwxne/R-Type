/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlDisplay
*/

#include "SfmlDisplay.hpp"

SfmlDisplay::SfmlDisplay(int widthWindow, int heightWindow, const std::string &nameWindow)
{
    _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(widthWindow, heightWindow), nameWindow);
    _window->setFramerateLimit(60);
    sf::Texture texture;
    texture.loadFromFile("assets/sprites/r_type_logo.png");
    _textureMap[TextureType::Player] = std::make_shared<sf::Texture>(texture);
}

SfmlDisplay::~SfmlDisplay()
{
}

sf::Event &SfmlDisplay::getEvent()
{
    return _event;
}

std::shared_ptr<sf::RenderWindow> SfmlDisplay::getWindow()
{
    return _window;
}

void SfmlDisplay::clear()
{
    _window->clear();
}

void SfmlDisplay::display()
{
    _window->display();
}

std::shared_ptr<sf::Texture> SfmlDisplay::getTexture(TextureType type)
{
    if (_textureMap.find(type) == _textureMap.end())
        return nullptr;
    return _textureMap[type];
}

std::shared_ptr<sf::Color> SfmlDisplay::getColor(ColorType type)
{
    if (_colorMap.find(type) == _colorMap.end())
        return nullptr;
    return _colorMap[type];
}