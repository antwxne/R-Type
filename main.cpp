/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** main
*/

#include "src/Graphical/Graphical.hpp"

int main()
{
    Graphical graphical;
    sf::Texture texture;
    sf::Sprite sprite;
    texture.loadFromFile("assets/sprites/r-typesheet1.gif");
    sprite.setTexture(texture);
    while (graphical.getWindow().isOpen())
    {
        while (graphical.getWindow().pollEvent(graphical.getEvent()))
        {
            if (graphical.getEvent().type == sf::Event::Closed)
                graphical.getWindow().close();
        }
        graphical.getWindow().clear();
        graphical.getWindow().draw(sprite);
        graphical.getWindow().display();
    }
}