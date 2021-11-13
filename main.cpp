/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** main
*/

#include "src/Graphical/SfmlDisplay.hpp"
#include "src/Graphical/SfmlParallax.hpp"

int main()
{
    SfmlDisplay graphical;
    SfmlParallax parallax;

    while (graphical.getWindow().isOpen())
    {
        while (graphical.getWindow().pollEvent(graphical.getEvent()))
        {
            if (graphical.getEvent().type == sf::Event::Closed)
                graphical.getWindow().close();
        }
        graphical.clear();
        parallax.update();
        parallax.draw(graphical.getWindow());
        graphical.display();
        //graphical.getWindow().draw(sprite);
    }
}

/*
Check les colisions entre toute les entité qui update les componants
*/