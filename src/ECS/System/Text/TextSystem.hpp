/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** TextSystem
*/

#ifndef TEXTSYSTEM_HPP_
#define TEXTSYSTEM_HPP_
#include "../ASystem.hpp"

class TextSystem : public ASystem {
    public:
        TextSystem(const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManager);
        ~TextSystem();
        void update() override;
    protected:
    private:
        bool checkAvailableEntity(std::size_t entity) const override;
        virtual void draw(const std::size_t entity);

};

#endif /* !TEXTSYSTEM_HPP_ */
