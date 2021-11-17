/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** DrawSystem
*/

#ifndef DRAWSYSTEM_HPP_
#define DRAWSYSTEM_HPP_

#include "../ASystem.hpp"
#include <vector>

class DrawSystem : public ASystem
{
    public:
        DrawSystem(std::shared_ptr<ComponentManager> componentManager);
        ~DrawSystem();
        void update() override;
    protected:
        bool checkAvailableEntity(size_t entity) const override;
    private:
        virtual void draw(const std::size_t entity);
};

#endif /* !DRAWSYSTEM_HPP_ */
