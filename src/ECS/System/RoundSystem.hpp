/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** RoundSystem
*/

#ifndef ROUNDSYSTEM_HPP_
#define ROUNDSYSTEM_HPP_

#include "ASystem.hpp"

class RoundSystem : public ASystem {
    public:
        RoundSystem(
            const std::shared_ptr<ComponentManager> &components, const std::shared_ptr<EntityManager> &entityManager);
        ~RoundSystem();
        void update() override;
    protected:
    private:
        bool checkAvailableEntity(std::size_t entity) const override;
        bool checkAvailableEntityEnemy(std::size_t entity) const;
};

#endif /* !ROUNDSYSTEM_HPP_ */
