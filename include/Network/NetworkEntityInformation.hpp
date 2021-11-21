/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** NetworkEntityInformation
*/

#ifndef NETWORKENTITYINFORMATION_HPP_
#define NETWORKENTITYINFORMATION_HPP_

#include "ECS/component.hpp"

struct NetworkEntityInformation
{
    std::size_t entity;
    Position position;
    Acceleration acceleration;
    Speed speed;
    Color color;
    Rotate rotate;
    Texture textureType;
    Scale scale;
    std::size_t totalTextureRect;
    float animationSpeed;
    sf::IntRect textureRect;
};

#endif /* !NETWORKENTITYINFORMATION_HPP_ */
