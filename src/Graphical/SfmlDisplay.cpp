/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlDisplay
*/

#include "SfmlDisplay.hpp"

SfmlDisplay::SfmlDisplay(int widthWindow, int heightWindow, const std::string &nameWindow) : _window(sf::VideoMode(widthWindow, heightWindow), nameWindow)
{
}

SfmlDisplay::~SfmlDisplay()
{
}

sf::Event &SfmlDisplay::getEvent()
{
    return _event;
}

sf::RenderWindow &SfmlDisplay::getWindow()
{
    return _window;
}

void SfmlDisplay::clear()
{
    _window.clear();
}

void SfmlDisplay::display()
{
    _window.display();
}