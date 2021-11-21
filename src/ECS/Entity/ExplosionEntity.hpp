/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** ExplosionEntity
*/

#ifndef EXPLOSIONENTITY_HPP_
#define EXPLOSIONENTITY_HPP_

#include "ECS/ECS.hpp"
#include "EntityManager.hpp"
#include "IEntityRegister.hpp"

class ExplosionEntity  : public IEntityRegister {
    public:
        ExplosionEntity(const Position &pos);
        ~ExplosionEntity();
        void create(
            const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManager) override;

    protected:
    private:
        Position _pos;
        sf::IntRect _textureRect;
};

#endif /* !EXPLOSIONENTITY_HPP_ */
