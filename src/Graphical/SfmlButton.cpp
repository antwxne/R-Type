/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlButton
*/

#include "SfmlButton.hpp"

SfmlButton::SfmlButton(const std::string &text, const sf::Vector2f &pos,
const float size, const sf::Font & font, bool isInputButton, bool isValidedButton)
{
    _text.setFont(font);
    _text.setFillColor(sf::Color::White);
    _text.setString(text);
    _text.setPosition(pos);
    _text.setCharacterSize(size);
    _isSelected = false;
    _isInputButton = isInputButton;
    _defaultTextSize = text.size();
    _isValidedButton = isValidedButton;
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

std::string SfmlButton::getText() const
{
    if (_isInputButton)
        return _text.getString().substring(_defaultTextSize);
    else
        return _text.getString();
}


void SfmlButton::addText(const std::string &text)
{
    if (_isInputButton == false)
        return;
    
    _text.setString(_text.getString() + text);
}

void SfmlButton::removeText()
{
    if (_text.getString().getSize() - 1 < _defaultTextSize)
        return;
    else
    {
        std::string str = _text.getString().toAnsiString();
        str.pop_back();
        _text.setString(str);
    }
}


bool SfmlButton::validate()
{
    return _isValidedButton;
}