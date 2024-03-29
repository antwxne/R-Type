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
        SfmlDrawSystem(const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManager);
        ~SfmlDrawSystem();
        void draw(const std::size_t entity) override;
        void setDisplay(std::shared_ptr<SfmlDisplay> display);
    protected:
        bool checkAvailableEntity(std::size_t entity) const override;
        void updateSprite(SfmlSprite &sprite, const std::size_t entity);
        void setPosition(SfmlSprite &sprite, const std::size_t entity);
        void setTexture(SfmlSprite &sprite, const std::size_t entity);
        void setScale(SfmlSprite &sprite, const std::size_t entity);
        void setRotate(SfmlSprite &sprite, const std::size_t entity);
        void setColor(SfmlSprite &sprite, const std::size_t entity);
        void setTextureRect(SfmlSprite &sprite);
    private:
        std::shared_ptr<SfmlDisplay> _display;
};

#endif /* !SfmlDrawSystem_HPP_ */
