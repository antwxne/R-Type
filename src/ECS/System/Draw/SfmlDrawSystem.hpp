/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlDrawSystem
*/

#ifndef SfmlDrawSystem_HPP_
#define SfmlDrawSystem_HPP_

#include "../Graphical/SfmlDisplay.hpp"
#include "DrawSystem.hpp"

class SfmlDrawSystem : public DrawSystem{
    public:
        SfmlDrawSystem(SfmlDisplay &display, std::shared_ptr<ComponentManager::ComponentsMap_t> &components);
        ~SfmlDrawSystem();
        void draw(const std::size_t entity) override;
    protected:
        void updateSprite(SfmlSprite &sprite, const std::size_t entity);
    private:
        SfmlDisplay &_display;
};

#endif /* !SfmlDrawSystem_HPP_ */
