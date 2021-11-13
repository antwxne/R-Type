/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Parallax
*/

#ifndef SFMLPARALLAX_HPP_
#define SFMLPARALLAX_HPP_

#include "./SfmlDisplay.hpp"
#include <iostream>

class SfmlParallax {
    public:
        SfmlParallax();
        ~SfmlParallax();

        void draw(sf::RenderWindow &window);
        void update();
        void moveRect(sf::IntRect &rect, const int offset, const int maxValue);
    protected:
    private:
        sf::Sprite _background;
        sf::Sprite _stars;
        sf::Sprite _planet;
        sf::Texture _texturePlanet;
        sf::Texture _textureBackground;
        sf::Texture _textureStars;
        sf::Clock _clock;
};
#endif /* !SFMLPARALLAX_HPP_ */
