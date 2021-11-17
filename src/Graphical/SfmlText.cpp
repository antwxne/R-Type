/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlText
*/

#include "SfmlText.hpp"

SfmlText::SfmlText(const std::string &text, const sf::Vector2f &pos, const float size, const sf::Font & font)
{
    _text.setFont(font);
    _text.setFillColor(sf::Color::White);
    _text.setString(text);
    _text.setPosition(pos);
    _text.setCharacterSize(size);
}

SfmlText::~SfmlText()
{
}

void SfmlText::draw(sf::RenderWindow &window)
{
    window.draw(_text);
}