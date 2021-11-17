/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** AISystem
*/

#include "AISystem.hpp"
#include "ECS/Component/Rectangle.hpp"
#include "ECS/Component/Transform/Position.hpp"
#include "ECS/Component/Tag.hpp"
#include "ECS/Component/AI.hpp"
#include "../../utils.hpp"
#include <cmath>
#include <cstdlib>

AISystem::AISystem(std::shared_ptr<ComponentManager> &components) : ASystem(components)
{
    _usedComponents.push_back(typeid(Rectangle).name());
    _usedComponents.push_back(typeid(Position).name());
    _usedComponents.push_back(typeid(Tag).name());
    _usedComponents.push_back(typeid(AI).name());
}

AISystem::~AISystem()
{
}

void AISystem::update()
{
    int i;
    for (std::size_t i = 0; i < MAX_ENTITIES; i++) {
        if (!checkAvailableEntity(i))
            continue;
        Tag &tag = _componentManager->getComponent<Tag>(i).value();
        AI &ai = _componentManager->getComponent<AI>(i).value();
        if (contains(tag.type, TagType::ENNEMY) && !contains(tag.type, TagType::BULLET)) {
            if (ai.isDestination) {
                setDestination(i);
            }
            else {
                setPath(i);
            }
        }
    }
}

void AISystem::setDestination(const std::size_t &entity)
{
    AI &ai = _componentManager->getComponent<AI>(entity).value();
    float x = rand() % ai.rectXStart + ai.rectXEnd;
    float y = rand() % ai.rectYStart + ai.rectYEnd;

    ai.x = x;
    ai.y = y;
    ai.isDestination = true;

}

void AISystem::setPath(const std::size_t &entity)
{
    AI &ai = _componentManager->getComponent<AI>(entity).value();
    Position &position = _componentManager->getComponent<Position>(entity).value();
    int addX = ai.x > position.x ? 1 : -1;
    int addY = ai.y > position.y ? 1 : -1;

    if (round(position.x) != round(ai.x))
        position.x += addX;
    if (round(position.y) != round(ai.y))
        position.y += addY;
    if (round(position.x) == round(ai.x) && round(position.y) == round(ai.y))
        ai.isDestination = false;
}