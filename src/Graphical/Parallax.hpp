/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Parallax
*/

#ifndef PARALLAX_HPP_
#define PARALLAX_HPP_

#include "./SfmlDisplay.hpp"
#include <iostream>

class Parallax {
    public:
        Parallax(sf::RenderWindow &window);
        ~Parallax();

        void draw();
        void update(sf::Clock &clock);

    protected:
    private:
        sf::RenderWindow &_window;
        sf::Sprite _background;
        sf::Sprite _stars;
        sf::Texture _textureBackground;
        sf::Texture _textureStars;
        //sf::Clock _clock;


};

#endif /* !PARALLAX_HPP_ */
