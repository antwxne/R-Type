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
        DrawSystem(std::shared_ptr<ComponentManager::ComponentsMap_t> &components);
        ~DrawSystem();
        void update() override;
    private:
        virtual void draw(const std::size_t entity);
};

#endif /* !DRAWSYSTEM_HPP_ */
