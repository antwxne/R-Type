/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** EnemyShootSystem
*/

#ifndef ENEMYSHOOTSYSTEM_HPP_
#define ENEMYSHOOTSYSTEM_HPP_

#include "ASystem.hpp"
#include "../component.hpp"
#include "../../utils.hpp"
#include "../Entity/BulletEntity.hpp"

class EnemyShootSystem : public ASystem {
    public:
        EnemyShootSystem(
            const std::shared_ptr<ComponentManager> &components, const std::shared_ptr<EntityManager> &entityManager);
        ~EnemyShootSystem();
        void update() override;
    protected:
    private:
        bool checkAvailableEntity(std::size_t entity) const override;
};

#endif /* !ENEMYSHOOTSYSTEM_HPP_ */
