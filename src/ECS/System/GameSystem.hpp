/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** GameSystem
*/

#ifndef GAMESYSTEM_HPP_
#define GAMESYSTEM_HPP_
#include "ASystem.hpp"

class GameSystem : public ASystem
{
    public:
        GameSystem(const std::shared_ptr<ComponentManager> &components, const std::shared_ptr<EntityManager> &entityManager);
        ~GameSystem();
        void update() override;
    protected:
    private:
};

#endif /* !GAMESYSTEM_HPP_ */
