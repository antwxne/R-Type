/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** TextEntity
*/

#ifndef TEXTENTITY_HPP_
#define TEXTENTITY_HPP_

#include "ECS/ECS.hpp"
#include "EntityManager.hpp"
#include "IEntityRegister.hpp"
#include "ECS/Component/Text.hpp"

class TextEntity : public IEntityRegister
{
    public:
        TextEntity();
        ~TextEntity();
        void setTextType(const TextType &textType);
        void setPos(const Position &pos);
        void setColor(const ColorType &color);
        void setSize(const int &size);
        void setFont(const std::string &font);
        void setTextValue(const std::string &textValue);
        void create(
            const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManager) override;
    
    protected:
    private:
        Position _pos;
        ColorType _color;
        int _size;
        std::string _font;
        std::string _textValue;
        TextType _textType;
};

#endif /* !TEXTENTITY_HPP_ */
