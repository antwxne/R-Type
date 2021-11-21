/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** BonusSystem
*/

#ifndef BONUSSYSTEM_HPP_
#define BONUSSYSTEM_HPP_

#include "ASystem.hpp"

class BonusSystem : public ASystem{
    public:
        BonusSystem(const std::shared_ptr<ComponentManager> &components, const std::shared_ptr<EntityManager> &entityManager);
        ~BonusSystem();
        void update() override;

    protected:
    private:
        bool checkAvailableEntity(std::size_t entity) const override;
};

#endif /* !BONUSSYSTEM_HPP_ */
