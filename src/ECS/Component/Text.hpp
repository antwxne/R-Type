/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlText
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_
#include "SFML/Graphics/Text.hpp"
#include <memory>

#ifdef __WIN32
enum TextType: int {
    SCORE,
    ROUND,
};

#else

enum TextType {
    SCORE,
    ROUND,
};

#endif

struct Text {
    std::shared_ptr<sf::Text> text;
    sf::Font font;
    std::string textValue;
    int size;
    sf::Color color;
    TextType type;

};
#endif /* !TEXT_HPP_ */
