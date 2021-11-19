/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** FirstMonsterEntity
*/

#ifndef FIRSTMONSTERENTITY_HPP_
#define FIRSTMONSTERENTITY_HPP_

#include "../../component.hpp"
#include "../../Component/ComponentManager.hpp"
#include "../EntityManager.hpp"
#include "../IEntityRegister.hpp"

class FirstMonsterEntity : public IEntityRegister {
    public:
        FirstMonsterEntity();
        ~FirstMonsterEntity();

        void create(std::shared_ptr<ComponentManager> componentManager,
            std::shared_ptr<EntityManager> entityManager
        ) override;
    protected:
    private:
        sf::IntRect _textureRect;
};

#endif /* !FIRSTMONSTERENTITY_HPP_ */
