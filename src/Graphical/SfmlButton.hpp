/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlButton
*/

#ifndef SFMLBUTTON_HPP_
#define SFMLBUTTON_HPP_

#include "SfmlDisplay.hpp"

class SfmlButton {
    public:
        SfmlButton(const std::string &text, const sf::Vector2f &pos, const float size, const sf::Font & font,
        bool isInputButton = false, bool isValidedButton = false);
        ~SfmlButton();
        void draw(sf::RenderWindow &window);
        void select();
        void unselect();
        void setText(const std::string &text);
        std::string getText() const;
        bool isSelected() const;
        void addText(const std::string &text);
        void removeText();
        bool validate();

    protected:
    private:
        sf::Text _text;
        int _defaultTextSize;
        bool _isInputButton;
        bool _isValidedButton;
        bool _isSelected;
};

#endif /* !SFMLBUTTON_HPP_ */
