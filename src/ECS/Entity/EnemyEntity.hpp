/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** EnemyEntity
*/

#ifndef ENEMYENTITY_HPP_
#define ENEMYENTITY_HPP_

#include "../ECS.hpp"
#include "EntityManager.hpp"
#include "IEntityRegister.hpp"

class EnemyEntity : public IEntityRegister {
    public:
        EnemyEntity();
        ~EnemyEntity();

        void setPosition(const Position &pos);
        void create(ECS &ecs);
        void create(std::shared_ptr<ComponentManager> componentManager,
            std::shared_ptr<EntityManager> entityManager
        ) override;
protected:
private:
    Position _pos;
    sf::IntRect _textureRect;
};

#endif /* !ENEMYENTITY_HPP_ */
