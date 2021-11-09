/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Graphical
*/

#ifndef GRAPHICAL_HPP_
#define GRAPHICAL_HPP_
#include "SFML/Graphics.hpp"


class Graphical {
    public:
        Graphical(int widthWindow = 1920, int heightWindow = 1080, const std::string &nameWindow = "window");
        ~Graphical();
        sf::RenderWindow &getWindow();
        sf::Event &getEvent();
    protected:
    private:
        sf::RenderWindow _window;
        sf::Event _event;

};

#endif /* !GRAPHICAL_HPP_ */
