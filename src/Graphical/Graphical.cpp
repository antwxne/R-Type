/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Graphical
*/

#include "Graphical.hpp"

Graphical::Graphical(int widthWindow, int heightWindow, const std::string &nameWindow) : _window(sf::VideoMode(widthWindow, heightWindow), nameWindow)
{
}

Graphical::~Graphical()
{
}

sf::Event &Graphical::getEvent()
{
    return _event;
}

sf::RenderWindow &Graphical::getWindow()
{
    return _window;
}

