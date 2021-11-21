/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** AccordeonMonsterEntity
*/

#ifndef ACCORDEONMONSTERENTITY_HPP_
#define ACCORDEONMONSTERENTITY_HPP_

#include "../../component.hpp"
#include "../../Component/ComponentManager.hpp"
#include "../EntityManager.hpp"
#include "../IEntityRegister.hpp"

class AccordeonMonsterEntity : public IEntityRegister {
    public:
        AccordeonMonsterEntity();
        ~AccordeonMonsterEntity();

        void create(const std::shared_ptr<ComponentManager> &componentManager,
            const std::shared_ptr<EntityManager> &entityManager
        ) override;
    protected:
    private:
        sf::IntRect _textureRect;
};

#endif /* !ACCORDEONMONSTERENTITY_HPP_ */
