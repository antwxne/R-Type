/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Parallax
*/

#include "Parallax.hpp"

Parallax::Parallax(sf::RenderWindow &window) : _window(window)
{
    _textureBackground.loadFromFile("assets/parallax/nebula_aqua.png", sf::IntRect(0, 0, 1920, 1080));
    _textureStars.loadFromFile("assets/parallax/stars_big_2.png");
    _background.setTexture(_textureBackground);
    _stars.setTexture(_textureStars);
}

Parallax::~Parallax()
{
}

void Parallax::draw()
{
    _window.draw(_background);
    _window.draw(_stars);
}

void Parallax::update(sf::Clock &clock)
{
    float elapsed = clock.getElapsedTime().asSeconds();
    if (elapsed > 0.01) {
        auto rect = _stars.getTextureRect();
        std::cout << rect.left << std::endl;
        rect.left += 1;
        _stars.setTextureRect(rect);
    }
    if (elapsed > 0.03) {
        auto rec = _background.getTextureRect();
        std::cout << rec.left << std::endl;
        rec.left += 1;
        _background.setTextureRect(rec);
        clock.restart();
    }
}