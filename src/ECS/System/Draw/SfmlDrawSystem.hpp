/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlDrawSystem
*/

#ifndef SfmlDrawSystem_HPP_
#define SfmlDrawSystem_HPP_

#include "../../../Graphical/SfmlDisplay.hpp"
#include "../../Component/SfmlSprite.hpp"
#include "DrawSystem.hpp"

class SfmlDrawSystem : public DrawSystem {
    public:
        SfmlDrawSystem(std::shared_ptr<ComponentManager> componentManager);
        ~SfmlDrawSystem();
        void draw(const std::size_t entity) override;
        void setDisplay(std::shared_ptr<SfmlDisplay> display);
    protected:
        void updateSprite(SfmlSprite &sprite, const std::size_t entity);
        void setPosition(SfmlSprite &sprite, const std::size_t entity);
        void setTexture(SfmlSprite &sprite, const std::size_t entity);
        void setScale(SfmlSprite &sprite, const std::size_t entity);
        void setRotate(SfmlSprite &sprite, const std::size_t entity);
        void setColor(SfmlSprite &sprite, const std::size_t entity);
        bool checkAvailableEntity(std::size_t entity) const override;
    private:
        std::shared_ptr<SfmlDisplay> _display;
};

#endif /* !SfmlDrawSystem_HPP_ */
