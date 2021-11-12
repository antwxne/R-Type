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

SfmlDrawSystem::SfmlDrawSystem(SfmlDisplay &display, std::shared_ptr<ComponentManager::ComponentsMap_t> &components)
:  _display(display), DrawSystem(components)
{
    _usedComponents.push_back(typeid(SfmlSprite));
}

SfmlDrawSystem::~SfmlDrawSystem()
{
}

void SfmlDrawSystem::draw(const std::size_t entity)
{
    auto& sprite = std::any_cast<SfmlSprite&>(_components->at(typeid(SfmlSprite))->getData(entity).value());

    updateSprite(sprite, entity);
    _display.getWindow().draw(sprite.sprite);
}

void SfmlDrawSystem::updateSprite(SfmlSprite &sprite, const std::size_t entity)
{
    setPosition(sprite, entity);
    if (sprite.sprite.getTexture() == nullptr)
        setTexture(sprite ,entity);
    setScale(sprite, entity);
    setRotate(sprite, entity);
    setColor(sprite, entity);
}

void SfmlDrawSystem::setPosition(SfmlSprite &sprite, const std::size_t entity)
{
    auto& position = std::any_cast<Position&>(_components->at(typeid(Position))->getData(entity).value());
    sprite.sprite.setPosition({position.x, position.y});
}

void SfmlDrawSystem::setTexture(SfmlSprite &sprite, const std::size_t entity)
{
    auto& texture = std::any_cast<Texture&>(_components->at(typeid(Texture))->getData(entity).value());

    std::shared_ptr<sf::Texture> sfmlTexture = _display.getTexture(texture.idTexture);

    if (sfmlTexture != nullptr)
        sprite.sprite.setTexture(*sfmlTexture);
}

void SfmlDrawSystem::setScale(SfmlSprite &sprite, const std::size_t entity)
{
    auto& scale = std::any_cast<Scale&>(_components->at(typeid(Scale))->getData(entity).value());

    sprite.sprite.setScale({scale.scaleX, scale.scaleY});
}

void SfmlDrawSystem::setRotate(SfmlSprite &sprite, const std::size_t entity)
{
    auto &rot = std::any_cast<Rotate&>(_components->at(typeid(Rotate))->getData(entity).value());

    sprite.sprite.setRotation(rot.r);
}

void SfmlDrawSystem::setColor(SfmlSprite &sprite, const std::size_t entity)
{
    auto &color = std::any_cast<Color&>(_components->at(typeid(Color))->getData(entity).value());

    std::shared_ptr<sf::Color> sfmlColor = _display.getColor(color.type);

    if (sfmlColor)
        sprite.sprite.setColor(*sfmlColor);
}