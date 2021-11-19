/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** ThirdMonsterEntity
*/

#ifndef THIRDMONSTERENTITY_HPP_
#define THIRDMONSTERENTITY_HPP_

#include "../../component.hpp"
#include "../../Component/ComponentManager.hpp"
#include "../EntityManager.hpp"
#include "../IEntityRegister.hpp"

class ThirdMonsterEntity : public IEntityRegister {
    public:
        ThirdMonsterEntity();
        ~ThirdMonsterEntity();

        void create(std::shared_ptr<ComponentManager> componentManager,
            std::shared_ptr<EntityManager> entityManager
        ) override;
    protected:
    private:
        sf::IntRect _textureRect;
};

#endif /* !THIRDMONSTERENTITY_HPP_ */
