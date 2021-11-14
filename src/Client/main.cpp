/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** main
*/

#include "../Graphical/SfmlDisplay.hpp"
#include "../Graphical/SfmlParallax.hpp"
#include "../ECS/ECS.hpp"
#include "../ECS/component.hpp"
#include "../ECS/system.hpp"

int main()
{
    SfmlDisplay graphical;
    SfmlParallax parallax;
    ECS ecs;

    //ecs.registerComponent<Position>();
    /*ecs.registerComponent<Texture>();
    ecs.registerComponent<Scale>();
    ecs.registerComponent<Rotate>();
    ecs.registerComponent<Color>();
    ecs.registerComponent<SfmlSprite>();
*/
    /*auto draw = ecs.registerSystem<SfmlDrawSystem>();

    Entity player = ecs.createEntity();

    ecs.subToComponent(player, Position{50, 50});
    ecs.subToComponent(player, Texture{TextureType::Player});
    ecs.subToComponent(player, Scale{1});
    ecs.subToComponent(player, Color{ColorType::None});
    ecs.subToComponent(player, SfmlSprite{sf::Sprite()});*/


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