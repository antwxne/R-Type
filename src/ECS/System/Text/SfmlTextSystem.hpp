/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlTextSystem
*/

#ifndef SFMLTEXTSYSTEM_HPP_
#define SFMLTEXTSYSTEM_HPP_

#include "TextSystem.hpp"
#include "../../../Graphical/SfmlDisplay.hpp"
#include "../../Component/SfmlText.hpp"

class SfmlTextSystem : public TextSystem {
    public:
        SfmlTextSystem(const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManager);
        ~SfmlTextSystem();
        void draw(const std::size_t entity) override;
        void setDisplay(std::shared_ptr<SfmlDisplay> display);
    protected:
        bool checkAvailableEntity(size_t entity) const override;
        void updateText(SfmlText &text, const std::size_t entity);
        void setPosition(SfmlText &text, const std::size_t entity);
        void setFont(SfmlText &text, const std::size_t entity);
        void setSize(SfmlText &text, const std::size_t entity);
        void setTextValue(SfmlText &text, const std::size_t entity);
        void setColor(SfmlText &text, const std::size_t entity);
    private:
        std::shared_ptr<SfmlDisplay> _display;

};

#endif /* !SFMLTEXTSYSTEM_HPP_ */