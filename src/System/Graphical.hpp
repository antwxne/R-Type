/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Graphical
*/

#ifndef GRAPHICAL_HPP_
#define GRAPHICAL_HPP_
#include "IGraphical.hpp"
#include <SFML/Window.hpp>

class Graphical : public IGraphical{
    public:
        Graphical();
        ~Graphical();

    protected:
    private:
        sf::Window window;
};

#endif /* !GRAPHICAL_HPP_ */
