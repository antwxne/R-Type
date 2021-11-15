/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-RtypeClient-thomas1.tricaud
** File description:
** RtypeClient
*/

#ifndef RtypeClient_HPP_
#define RtypeClient_HPP_

#include "../Graphical/SfmlDisplay.hpp"
#include "../Graphical/SfmlParallax.hpp"
#include "../Graphical/SfmlMenu.hpp"
#include "../Graphical/SfmlEventFactory.hpp"


enum GameState
{
    ConnectMenu,
    MainMenu,
    GameLobby,
    Game,
    Options,
};

class RtypeClient {
    public:
        RtypeClient();
        ~RtypeClient();
        void start();

    private:
        void initMenu();
        void run();
        void manageState();
        void manageConnectMenu();
        void handleEvents(const sf::Event& event);
        void handleTextInput(const sf::Event& event);
    private:
        GameState _state;

        SfmlDisplay _graphical;
        SfmlEventFactory _eventFactory;
        SfmlParallax _parallax;
        
        SfmlMenu _connectMenu;

        sf::Sprite _spriteLogo;
        sf::Texture _textureLogo;
};

#endif /* !RtypeClient_HPP_ */