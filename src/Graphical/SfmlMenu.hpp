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
#include "SfmlText.hpp"

class SfmlMenu {
    public:
        SfmlMenu();
        ~SfmlMenu();
        void draw(sf::RenderWindow &window);
        void addButton(const std::string &name, float size, bool isInputButton = false, bool isValidedButton = false);
        void addText(const std::string &name, float size);
        void handleEvent(const ControlGame control);
        void handleTextInput(const std::string &text);
        bool isValided() const;
        void resetValided();
        std::string getButtonText(int index) const;
        void resetButtons();
        void resetTexts();
        int getSelectedIndex() const;
    private:
        void selectPreviousButton();
        void selectNextButton();
        void setSelectedButton(int index);
        void handleTextDelete();
        void handleValidate();
    private:
        int _nbButtons;
        int _nbText;
        int _selectedIndex;
        bool _isValided;
        std::list<SfmlButton> _buttonList;
        std::list<SfmlText> _textList;
        sf::Font _font;

};

#endif /* !SFMLMENU_HPP_ */
