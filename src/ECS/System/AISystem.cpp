/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** AISystem
*/

#include "AISystem.hpp"
#include "ECS/Component/Rectangle.hpp"
#include "ECS/Component/Acceleration.hpp"
#include "ECS/Component/Transform/Position.hpp"
#include "ECS/Component/Tag.hpp"
#include "ECS/Component/AI.hpp"
#include "../../utils.hpp"
#include <cmath>
#include <cstdlib>

AISystem::AISystem(
    const std::shared_ptr<ComponentManager> &components, const std::shared_ptr<EntityManager> &entityManager) : ASystem(components, entityManager)
{
}

AISystem::~AISystem()
{
}

void AISystem::update()
{
    auto &tags = _componentManager->getComponentsList<Tag>();
    auto &ais = _componentManager->getComponentsList<AI>();
    const auto &entities = _entityManager->getCurrentEntities();
    std::size_t id;

    for (const auto &entity : entities) {
        entity >> id;
        if (!checkAvailableEntity(id))
            continue;
        Tag &tag = tags[entity].value();
        AI &ai = ais[entity].value();
        if (contains(tag.type, TagType::ENNEMY) && !contains(tag.type, TagType::BULLET)) {
            if (!ai.isDestination) {
                setDestination(id);
            }
            else {
                setPath(id);
            }
        }
    }
}

void AISystem::setDestination(const std::size_t &entity)
{
    AI &ai = _componentManager->getComponent<AI>(entity).value();
    Rectangle &rectangle = _componentManager->getComponent<Rectangle>(entity).value();

    float x = rand() % ((ai.rectXEnd - rectangle.width) - ai.rectXStart + 1) + ai.rectXStart;
    float y = rand() % ((ai.rectYEnd - rectangle.height) - ai.rectYStart + 1) + ai.rectYStart;

    ai.x = x;
    ai.y = y;
    ai.isDestination = true;

}

void AISystem::setPath(const std::size_t &entity)
{
    AI &ai = _componentManager->getComponent<AI>(entity).value();
    Position &position = _componentManager->getComponent<Position>(entity).value();
    Acceleration &acceleration = _componentManager->getComponent<Acceleration>(entity).value();
    int addX = ai.x > position.x ? 1 : -1;
    int addY = ai.y > position.y ? 1 : -1;
    
    if (round(position.x) != round(ai.x))
         acceleration.x = addX;
    else
        acceleration.x = 0;
    if (round(position.y) != round(ai.y))
         acceleration.y = addY;
    else
        acceleration.y = 0;
    if (round(position.x) == round(ai.x) && round(position.y) == round(ai.y))
        ai.isDestination = false;
}

bool AISystem::checkAvailableEntity(std::size_t entity) const
{
    const auto &position = _componentManager->getComponentsList<Position>();
    const auto &ai = _componentManager->getComponentsList<AI>();
    const auto &tag = _componentManager->getComponentsList<Tag>();
    const auto &rectangle = _componentManager->getComponentsList<Rectangle>();
    const auto &acceleration = _componentManager->getComponentsList<Acceleration>();

    return position[entity].has_value() && ai[entity].has_value() && tag[entity].has_value() && rectangle[entity].has_value() && acceleration[entity].has_value();
}
