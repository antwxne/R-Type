/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** BonusEntity
*/

#ifndef BONUSENTITY_HPP_
#define BONUSENTITY_HPP_

#include "../ECS.hpp"
#include "EntityManager.hpp"
#include "IEntityRegister.hpp"

class BonusEntity : public IEntityRegister {
    public:
        BonusEntity(const Position &pos, BonusType type);
        ~BonusEntity();
        void create(const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManager) override;

    protected:
    private:
        Position _pos;
        BonusType _type;
};

#endif /* !BONUSENTITY_HPP_ */
