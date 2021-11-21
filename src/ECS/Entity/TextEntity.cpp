/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** TextEntity
*/

#include "TextEntity.hpp"

TextEntity::TextEntity() : IEntityRegister()
{
}

TextEntity::~TextEntity()
{
}

void TextEntity::setPos(const Position &pos)
{
    _pos = pos;
}

void TextEntity::setColor(const ColorType &color)
{
    _color = color;
}

void TextEntity::setSize(const int &size)
{
    _size = size;
}

void TextEntity::setFont(const std::string &font)
{
    _font = font;
}

void TextEntity::setTextValue(const std::string &textValue)
{
    _textValue = textValue;
}

void TextEntity::setTextType(const TextType &textType)
{
    _textType = textType;
}


void TextEntity::create(const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManager)
{
    _entity = entityManager->create();
    std::shared_ptr<sf::Text> text = std::make_shared<sf::Text>();
    sf::Font font;
    if (!font.loadFromFile(_font))
    {
        throw std::runtime_error("No Font");
    }
    componentManager->subToComponent(_entity, _pos);
    componentManager->subToComponent(_entity, Text{text, font, _textValue, _size, sf::Color::White, _textType});
}
