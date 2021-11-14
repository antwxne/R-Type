/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlButton
*/

#include "SfmlButton.hpp"

SfmlButton::SfmlButton(const std::string &text, const sf::Vector2 &pos,
const float size)
{
    _text.setFillColor(sf::Color::White);
    _text.setString(text);
    _text.setPosition(pos);
    _text.setCharacterSize(size);
    _isSelected = false;
}

SfmlButton::~SfmlButton()
{
}

void SfmlButton::draw(sf::RenderWindow &window)
{
    window.draw(_text);
}

void SfmlButton::select()
{
    _isSelected = true;
    _text.setFillColor(sf::Color::Red);
}

void SfmlButton::unselect()
{
    _isSelected = false;
    _text.setFillColor(sf::Color::White);
}

bool SfmlButton::isSelected() const
{
    return _isSelected;
}

void SfmlButton::setText(const std::string &text)
{
    _text.setString(text);
}

std::string SfmlButton::getText()
{
    return _text.getString();
}