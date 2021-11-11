/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlDisplay
*/

#ifndef SFMLDISPLAY_HPP_
#define SFMLDISPLAY_HPP_
#include "SFML/Graphics.hpp"
#include <map>
#include "IGraphical.hpp"
#include "graphical.hpp"

class SfmlDisplay : public IGraphical {
    public:
        SfmlDisplay(int widthWindow = 1920, int heightWindow = 1080, const std::string &nameWindow = "window");
        ~SfmlDisplay();
        sf::RenderWindow &getWindow();
        sf::Event &getEvent();
        void clear() override;
        void display() override;
    protected:
    private:
        sf::RenderWindow _window;
        sf::Event _event;
        std::map<TextureType, sf::Texture> _textureMap;
};

#endif /* !SFMLDISPLAY_HPP_ */
