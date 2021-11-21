/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** GeldMonsterEntity
*/

#ifndef GELDMONSTERENTITY_HPP_
#define GELDMONSTERENTITY_HPP_

#include "../../component.hpp"
#include "../../Component/ComponentManager.hpp"
#include "../EntityManager.hpp"
#include "../IEntityRegister.hpp"

class GeldMonsterEntity : public IEntityRegister {
    public:
        GeldMonsterEntity();
        ~GeldMonsterEntity();

        void create(const std::shared_ptr<ComponentManager> &componentManager,
            const std::shared_ptr<EntityManager> &entityManager
        ) override;
    protected:
    private:
        sf::IntRect _textureRect;
};

#endif /* !GeldMONSTERENTITY_HPP_ */
