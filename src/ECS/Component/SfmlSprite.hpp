/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <memory>
#include <string>
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/Clock.hpp"

struct SfmlSprite
{
    std::shared_ptr<sf::Sprite> sprite;
    sf::IntRect textureRect;
    size_t totalRect;
    size_t actualRect;
    float animationSpeed;
    sf::Clock clock;
};

#endif /* !SPRITE_HPP_ */
