/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** main
*/

#include "src/Graphical/SfmlDisplay.hpp"
#include "src/Graphical/Parallax.hpp"

int main()
{
    SfmlDisplay graphical;
    Parallax parallax(graphical.getWindow());
    sf::Clock clock;
    // sf::Texture texture;
    // sf::Sprite sprite;

    // texture.loadFromFile("assets/parallax/nebula_aqua.png");
    // sprite.setTexture(texture);
    while (graphical.getWindow().isOpen())
    {
        while (graphical.getWindow().pollEvent(graphical.getEvent()))
        {
            if (graphical.getEvent().type == sf::Event::Closed)
                graphical.getWindow().close();
        }
        graphical.clear();
        parallax.update(clock);
        parallax.draw();
        graphical.display();
        //graphical.getWindow().draw(sprite);
    }
}

/*
Check les colisions entre toute les entité qui update les componants
*/