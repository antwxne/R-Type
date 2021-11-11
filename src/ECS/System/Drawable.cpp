/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Drawable
*/

#include "Drawable.hpp"

Drawable::Drawable()
{
}

Drawable::~Drawable()
{
}

void Drawable::loadTexture(const Entity &entity)
{
    _texture.setSmooth(true);
    if (!_texture.loadFromFile("image.png" /*, lataille du rect*/))
    {
        throw std::runtime_error("Error load texture Drawable");
    }
    _sprite.setTexture(_texture);

}

void Drawable::draw(const Entity &entity, Graphical &graphical)
{
    // graphical.getWindow().draw(entity sprite);
    // draw dans la windows
}
