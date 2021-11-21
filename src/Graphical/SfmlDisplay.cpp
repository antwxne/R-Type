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
    initTexture();
    initColors();
}

SfmlDisplay::~SfmlDisplay()
{
}

void SfmlDisplay::initColors()
{
    _colorMap[ColorType::Blue] = std::make_shared<sf::Color>(sf::Color::Blue);
    _colorMap[ColorType::Red] = std::make_shared<sf::Color>(sf::Color::Red);
    _colorMap[ColorType::Yellow] = std::make_shared<sf::Color>(sf::Color::Yellow);
    _colorMap[ColorType::Green] = std::make_shared<sf::Color>(sf::Color::Green);
}

void SfmlDisplay::initTexture()
{
    sf::Texture texture;
    texture.loadFromFile("assets/sprites/spaceship.gif");
    _textureMap[TextureType::Player] = std::make_shared<sf::Texture>(texture);
    texture.loadFromFile("assets/sprites/bullet.png");
    _textureMap[TextureType::Bullet] = std::make_shared<sf::Texture>(texture);
    texture.loadFromFile("assets/sprites/enemy4.gif");
    _textureMap[TextureType::Enemy] = std::make_shared<sf::Texture>(texture);
    texture.loadFromFile("assets/sprites/enemy2.gif");
    _textureMap[TextureType::Enemy2] = std::make_shared<sf::Texture>(texture);
    texture.loadFromFile("assets/sprites/enemy5.gif");
    _textureMap[TextureType::Enemy3] = std::make_shared<sf::Texture>(texture);
    texture.loadFromFile("assets/sprites/explode.png");
    _textureMap[TextureType::Explosions] = std::make_shared<sf::Texture>(texture);
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