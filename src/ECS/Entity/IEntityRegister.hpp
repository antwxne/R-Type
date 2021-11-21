/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** IEntityRegister
*/

#ifndef IENTITYREGISTER_HPP_
#define IENTITYREGISTER_HPP_

#include "../component.hpp"
#include "../Component/ComponentManager.hpp"
#include "EntityManager.hpp"

class IEntityRegister {
public:
    IEntityRegister();
    ~IEntityRegister() = default;
    virtual void create(
        const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManager) = 0;
    const Entity &getEntity() const;
    size_t getEntityValue() const;
    void setPosition(const Position &pos);

protected:
    Position _pos;
    Entity _entity;
};

#endif /* !IENTITYREGISTER_HPP_ */
