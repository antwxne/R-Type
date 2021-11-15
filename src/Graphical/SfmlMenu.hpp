/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlMenu
*/

#ifndef SFMLMENU_HPP_
#define SFMLMENU_HPP_

#include <list>
#include "SfmlDisplay.hpp"
#include "SfmlButton.hpp"
#include "SfmlEventFactory.hpp"

class SfmlMenu {
    public:
        SfmlMenu();
        ~SfmlMenu();
        void draw(sf::RenderWindow &window);
        void addButton(const std::string &name, float size, bool isInputButton = false);
        void handleEvent(const ControlGame control);
        void handleTextInput(const std::string &text);
    private:
        void selectPreviousButton();
        void selectNextButton();
        void setSelectedButton(int index);
        void handleTextDelete();
    private:
        int _nbButtons;
        int _selectedIndex;
        std::list<SfmlButton> _buttonList;
        sf::Font _font;

};

#endif /* !SFMLMENU_HPP_ */
