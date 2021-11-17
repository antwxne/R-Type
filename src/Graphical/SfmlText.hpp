/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlText
*/


#ifndef SFMLTEXT_HPP_
#define SFMLTEXT_HPP_

#include "SfmlDisplay.hpp"

class SfmlText {
    public:
        SfmlText(const std::string &text, const sf::Vector2f &pos, const float size, const sf::Font & font);
        ~SfmlText();
        void draw(std::shared_ptr<sf::RenderWindow> window);

    protected:
    private:
        sf::Text _text;
};

#endif /* !SFMLTEXT_HPP_ */
