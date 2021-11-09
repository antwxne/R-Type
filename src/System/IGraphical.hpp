/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** IGraphical
*/

#ifndef IGRAPHICAL_HPP_
#define IGRAPHICAL_HPP_
#include "../Entity/Entity.hpp"
#include <memory>

class IGraphical {
    public:
        virtual ~IGraphical() = default;
        virtual void draw(const Entity &entity) = 0;
        virtual int getEvent() = 0;
    protected:
    private:
};

#endif /* !IGRAPHICAL_HPP_ */
