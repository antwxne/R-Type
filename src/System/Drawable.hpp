/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Drawable
*/

#ifndef DRAWABLE_HPP_
#define DRAWABLE_HPP_

#include "../Entity/Entity.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"


class Drawable {
    public:
        Drawable();
        ~Drawable();
        void loadTexture(const Entity &entity);
        void draw(const Entity &entity);

    protected:
    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
        //shared_ptr<ComposantManagement

};

#endif /* !DRAWABLE_HPP_ */
