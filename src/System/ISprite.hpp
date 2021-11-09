/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** ISprite
*/

#ifndef ISPRITE_HPP_
#define ISPRITE_HPP_
#include <string>
#include "../Entity/Entity.hpp"

class ISprite {
    public:
        virtual ~ISprite() = default;
        virtual void setTexture(const Entity &entity) = 0;
        virtual void draw() = 0;
    protected:
    private:
};

#endif /* !ISPRITE_HPP_ */
