/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SecondMonsterEntity
*/

#ifndef SECONDMONSTERENTITY_HPP_
#define SECONDMONSTERENTITY_HPP_

#include "../../component.hpp"
#include "../../Component/ComponentManager.hpp"
#include "../EntityManager.hpp"
#include "../IEntityRegister.hpp"

class SecondMonsterEntity : public IEntityRegister {
    public:
        SecondMonsterEntity();
        ~SecondMonsterEntity();

        void create(const std::shared_ptr<ComponentManager> &componentManager,
            const std::shared_ptr<EntityManager> &entityManager
        ) override;
    protected:
    private:
        sf::IntRect _textureRect;
};

#endif /* !SECONDMONSTERENTITY_HPP_ */
