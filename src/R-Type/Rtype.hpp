/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Rtype
*/

#ifndef RTYPE_HPP_
#define RTYPE_HPP_

#include "../Graphical/SfmlDisplay.hpp"
#include "../Graphical/SfmlParallax.hpp"
#include "../ECS/ECS.hpp"
#include "../ECS/component.hpp"
#include "../ECS/system.hpp"

enum GameState
{
    ConnectMenu,
    MainMenu,
    GameLobby,
    Game,
    Options,
};

class Rtype {
    public:
        Rtype();
        ~Rtype();
        void start();

    protected:
    private:
        SfmlDisplay _graphical;
        SfmlParallax _parallax;
        ECS _ecs;
        GameState _state;

        sf::Sprite _spriteLogo;
        sf::Texture _textureLogo;

        void run();
        void manageState();
        void manageConnectMenu();
};

#endif /* !RTYPE_HPP_ */
