/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlTextSystem
*/

#include "SfmlTextSystem.hpp"
#include "../../Component/Transform/Position.hpp"
#include "../../Component/Color.hpp"

SfmlTextSystem::SfmlTextSystem(const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManager) : TextSystem(componentManager, entityManager)
{
}

SfmlTextSystem::~SfmlTextSystem()
{
}

void SfmlTextSystem::draw(const std::size_t entity)
{
    auto &text = _componentManager->getComponent<Text>(entity).value();
    updateText(text, entity);
    _display->getWindow()->draw(*text.text);
}

void SfmlTextSystem::setDisplay(std::shared_ptr<SfmlDisplay> display)
{
    _display = display;
}

bool SfmlTextSystem::checkAvailableEntity(size_t entity) const
{
    const auto &pos = _componentManager->getComponentsList<Position>();
    const auto &text = _componentManager->getComponentsList<Text>();
    return pos[entity].has_value() && text[entity].has_value();
}

void SfmlTextSystem::updateText(Text &text, const std::size_t entity)
{
    setPosition(text, entity);
    setTextValue(text, entity);
    setSize(text, entity);
    setFont(text, entity);
    setColor(text, entity);
}

void SfmlTextSystem::setPosition(Text &text, const std::size_t entity)
{
    auto &position = _componentManager->getComponent<Position>(entity).value();

    text.text->setPosition({position.x, position.y});
}

void SfmlTextSystem::setTextValue(Text &text, const std::size_t entity)
{
    auto &sfmlText = _componentManager->getComponent<Text>(entity).value();

    text.text->setString(sfmlText.textValue);
}

void SfmlTextSystem::setFont(Text &text, const std::size_t entity)
{
    auto &sfmlText = _componentManager->getComponent<Text>(entity).value();

    text.text->setFont(sfmlText.font);
}

void SfmlTextSystem::setSize(Text &text, const std::size_t entity)
{
    auto &sfmlText = _componentManager->getComponent<Text>(entity).value();

    text.text->setCharacterSize(sfmlText.size);
}

void SfmlTextSystem::setColor(Text &text, const std::size_t entity)
{
    auto &sfmlText = _componentManager->getComponent<Text>(entity).value();

    text.text->setFillColor(sfmlText.color);
}