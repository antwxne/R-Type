/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** BulletEntity
*/

#ifndef BULLETENTITY_HPP_
#define BULLETENTITY_HPP_

#include "../ECS.hpp"
#include "EntityManager.hpp"
#include "IEntityRegister.hpp"

class BulletEntity : public IEntityRegister {
    public:
        BulletEntity(const Position &pos, const bool isBulletFriend);
        ~BulletEntity();

        void create(const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManager) override;

    protected:
    private:
        Position _pos;
        bool _isBulletFriend;
        sf::IntRect _rect;
};

#endif /* !BULLETENTITY_HPP_ */
