/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** RoundEntity
*/

#ifndef ROUNDENTITY_HPP_
#define ROUNDENTITY_HPP_
#include "IEntityRegister.hpp"
#include "ECS/component.hpp"

class RoundEntity : public IEntityRegister {
    public:
        RoundEntity(const Round &round);
        ~RoundEntity();
        void create(const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManager) override;
    protected:
    private:
        Round _round;
};

#endif /* !ROUNDENTITY_HPP_ */
