/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlMenu
*/

#include "SfmlMenu.hpp"

SfmlMenu::SfmlMenu()
{
    _nbButtons = 0;
    _selectedIndex = 0;
    _font.loadFromFile("assets/font/origintech.ttf");
}

SfmlMenu::~SfmlMenu()
{
}


void SfmlMenu::draw(sf::RenderWindow &window)
{
    for (auto &i : _buttonList)
        i.draw(window);
}

void SfmlMenu::addButton(const std::string &name, float size, bool isInputButton)
{
    sf::Vector2f pos;

    pos.x = 800;
    pos.y = (_nbButtons + 1) * 200 + 50;

    SfmlButton button(name, pos, size, _font, isInputButton);

    if (_nbButtons == 0)
        button.select();

    _buttonList.push_back(button);
    _nbButtons++;
}

void SfmlMenu::handleEvent(const ControlGame control)
{
    switch (control)
    {
        case ControlGame::UP:
            selectPreviousButton();
            break;
        case  ControlGame::DOWN:
            selectNextButton();
            break;
        case ControlGame::DELETE:
            handleTextDelete();
        default:
            return;
    }
}

void SfmlMenu::handleTextDelete()
{
    int idx = 0;

    for (auto &button : _buttonList)
    {
        if (idx == _selectedIndex)
        {
            button.removeText();
            return;
        }
        idx++;
    }
}

void SfmlMenu::selectPreviousButton()
{
    int selectedIndex = _selectedIndex - 1;

    if (selectedIndex < 0)
        selectedIndex = _buttonList.size() - 1;
    setSelectedButton(selectedIndex);
}

void SfmlMenu::selectNextButton()
{
    int selectedIndex = _selectedIndex + 1;

    if (selectedIndex >= (int) _buttonList.size())
        selectedIndex = 0;
    setSelectedButton(selectedIndex);
}

void SfmlMenu::setSelectedButton(int index)
{
    int idx = 0;

    _selectedIndex = index;

    for (auto &button : _buttonList)
    {
        if (idx == index)
        {
            button.select();
        }
        else
            button.unselect();
        idx++;
    }
}

void SfmlMenu::handleTextInput(const std::string &text)
{
    int idx = 0;
    for (auto &button : _buttonList)
    {
        if (idx == _selectedIndex)
        {
            button.addText(text);
            return;
        }
        idx++;
    }
}