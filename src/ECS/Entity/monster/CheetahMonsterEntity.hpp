/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** CheetahMonsterEntity
*/

#ifndef CHEETAHMONSTERENTITY_HPP_
#define CHEETAHMONSTERENTITY_HPP_

#include "../../component.hpp"
#include "../../Component/ComponentManager.hpp"
#include "../EntityManager.hpp"
#include "../IEntityRegister.hpp"

class CheetahMonsterEntity : public IEntityRegister {
    public:
        CheetahMonsterEntity();
        ~CheetahMonsterEntity();

        void create(const std::shared_ptr<ComponentManager> &componentManager,
            const std::shared_ptr<EntityManager> &entityManager
        ) override;
    protected:
    private:
        sf::IntRect _textureRect;
};

#endif /* !CheetahMONSTERENTITY_HPP_ */
