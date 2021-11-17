/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** IEntityRegister
*/

#ifndef IENTITYREGISTER_HPP_
#define IENTITYREGISTER_HPP_

#include "ECS/ECS.hpp"

class IEntityRegister {
public:
    IEntityRegister();
    ~IEntityRegister() = default;
    virtual void create(ECS &ecs) = 0;
    const Entity &getEntity() const;

protected:
    Entity _entity;
};

#endif /* !IENTITYREGISTER_HPP_ */
