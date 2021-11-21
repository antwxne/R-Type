/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlText
*/

#ifndef SFMLTEXT_HPP_
#define SFMLTEXT_HPP_
#include "SFML/Graphics/Text.hpp"
#include <memory>

struct SfmlText {
    std::shared_ptr<sf::Text> text;
    sf::Font font;
    std::string textValue;
    int size;
    sf::Color color;
};
#endif /* !SFMLTEXT_HPP_ */
