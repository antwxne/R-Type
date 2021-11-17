/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** ShootSystem
*/

#ifndef SHOOTSYSTEM_HPP_
#define SHOOTSYSTEM_HPP_

#include "ASystem.hpp"
#include "ECS/Component/Tag.hpp"
#include "ECS/Component/Firerate.hpp"
#include "../../utils.hpp"

class ShootSystem : public ASystem {
    public:
        ShootSystem(std::shared_ptr<ComponentManager> &components);
        ~ShootSystem();

        void update() override;
        void shoot(const std::size_t &entity);
    protected:
    private:
        bool checkAvailableEntity(std::size_t entity) const override;

};

#endif /* !SHOOTSYSTEM_HPP_ */
