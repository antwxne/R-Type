/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlDrawSystem
*/

#include "SfmlDrawSystem.hpp"
#include "../../Component/Transform/Position.hpp"
#include "../../Component/Texture.hpp"
#include "../../Component/Transform/Scale.hpp"
#include "../../Component/Transform/Rotate.hpp"
#include "../../Component/Color.hpp"

SfmlDrawSystem::SfmlDrawSystem(
    std::shared_ptr<ComponentManager> componentManager
) : DrawSystem(componentManager)
{
    _usedComponents.push_back(typeid(SfmlSprite).name());
}

SfmlDrawSystem::~SfmlDrawSystem()
{
}

void SfmlDrawSystem::draw(const std::size_t entity)
{
    auto &sprite = _componentManager->getComponent<SfmlSprite>(entity).value();
    updateSprite(sprite, entity);
    _display->getWindow()->draw(*sprite.sprite);
}

void SfmlDrawSystem::updateSprite(SfmlSprite &sprite, const std::size_t entity)
{
    setPosition(sprite, entity);

    if (sprite.sprite->getTexture() == nullptr) {
        setTexture(sprite, entity);
    }
    setScale(sprite, entity);
    setRotate(sprite, entity);
    setColor(sprite, entity);

}

void SfmlDrawSystem::setPosition(SfmlSprite &sprite, const std::size_t entity)
{
    auto &position = _componentManager->getComponent<Position>(entity).value();

    sprite.sprite->setPosition({position.x, position.y});
}

void SfmlDrawSystem::setTexture(SfmlSprite &sprite, const std::size_t entity)
{
    auto &texture = _componentManager->getComponent<Texture>(entity).value();

    std::shared_ptr<sf::Texture> sfmlTexture = _display->getTexture(
        texture.idTexture);

    if (sfmlTexture != nullptr) {
        sprite.sprite->setTexture(*sfmlTexture);
    }
}

void SfmlDrawSystem::setScale(SfmlSprite &sprite, const std::size_t entity)
{
    auto &scale = _componentManager->getComponent<Scale>(entity).value();

    sprite.sprite->setScale({scale.scaleX, scale.scaleY});
}

void SfmlDrawSystem::setRotate(SfmlSprite &sprite, const std::size_t entity)
{
    auto &rot = _componentManager->getComponent<Rotate>(entity).value();

    sprite.sprite->setRotation(rot.r);
}

void SfmlDrawSystem::setColor(SfmlSprite &sprite, const std::size_t entity)
{
    auto &color = _componentManager->getComponent<Color>(entity).value();

    std::shared_ptr<sf::Color> sfmlColor = _display->getColor(color.type);

    if (sfmlColor) {
        sprite.sprite->setColor(*sfmlColor);
    }
}

void SfmlDrawSystem::setDisplay(std::shared_ptr<SfmlDisplay> display)
{
    _display = display;
}
