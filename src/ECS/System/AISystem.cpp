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
#include "../../utils.hpp"

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
    for (std::size_t i = 0; i < MAX_ENTITIES; i++) {
        if (!checkAvailableEntity(i))
            continue;
        Tag &tag = _componentManager->getComponent<Tag>(i).value();
        if (contains(tag.type, TagType::ENNEMY)) {
            if (contains(tag.type, TagType::BULLET)) {

            } else {
                
            }
        }
    }
}
