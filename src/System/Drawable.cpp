/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Drawable
*/

#include "Drawable.hpp"

Drawable::Drawable(std::shared_ptr<ComponentsMap_t> &)
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
        throw std::exception("yo le rap");
    }
    _sprite.setTexture(_texture);

}

void Drawable::draw(const Entity &entity)
{
    // draw dans la windows
}
