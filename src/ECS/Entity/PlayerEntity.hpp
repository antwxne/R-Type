/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** PlayerEntity
*/

#ifndef PLAYERENTITY_HPP_
#define PLAYERENTITY_HPP_

#include "../ECS.hpp"
#include "EntityManager.hpp"
#include "IEntityRegister.hpp"


class PlayerEntity : public IEntityRegister {
    public:
        PlayerEntity(const Position &pos, ColorType color);
        ~PlayerEntity();

        void create(ECS &ecs);

    protected:
    private:
        Position _pos;
        ColorType _color;
        sf::IntRect _textureRect;
};

#endif /* !PLAYERENTITY_HPP_ */
