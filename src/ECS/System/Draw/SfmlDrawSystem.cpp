/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlDrawSystem
*/

#include "SfmlDrawSystem.hpp"
#include "../Component/SfmlSprite.hpp"
#include "../Component/Transform/Position.hpp"
#include "../Component/Texture.hpp"

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
    auto& position = std::any_cast<Position&>(_components->at(typeid(Position))->getData(entity).value());

    sprite.sprite.setPosition({position.x, position.y});
}