/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Parallax
*/

#include "SfmlParallax.hpp"

SfmlParallax::SfmlParallax()
{
    _textureBackground.loadFromFile("assets/parallax/nebula_aqua.png", sf::IntRect(0, 0, 0, 0));
    _textureStars.loadFromFile("assets/parallax/stars_big_2.png");
    _texturePlanet.loadFromFile("assets/parallax/planet.png");
    _background.setTexture(_textureBackground);
    _stars.setTexture(_textureStars);
    _planet.setTexture(_texturePlanet);
    _planet.setPosition(1920, 0);
}

SfmlParallax::~SfmlParallax()
{
}

void SfmlParallax::draw(sf::RenderWindow &window)
{
    window.draw(_background);
    window.draw(_planet);
    window.draw(_stars);
}

void SfmlParallax::update(sf::Clock &clock)
{
    float elapsed = clock.getElapsedTime().asSeconds();
    sf::IntRect rect;

    if (elapsed > 0.01) {
        rect = _stars.getTextureRect();
        moveRect(rect, 5, 2176);
        _stars.setTextureRect(rect);
    }
    if (elapsed > 0.01) {
        sf::Vector2f pos = _planet.getPosition();
        pos.x -= 3;
        if (pos.x <= -3800)
            pos.x = 1920;
        std::cout << pos.x << std::endl;
        _planet.setPosition(pos);
    }
    if (elapsed > 0.03) {
        rect = _background.getTextureRect();
        moveRect(rect, 2, 2176);
        _background.setTextureRect(rect);
        clock.restart();
    }
}

void SfmlParallax::moveRect(sf::IntRect &rect, const int offset, const int maxValue)
{
    rect.left = rect.left + offset;
    if (rect.left >= maxValue)
        rect.left = 0;
}