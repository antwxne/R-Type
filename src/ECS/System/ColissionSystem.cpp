/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** ColissionSystem
*/

#include "ColissionSystem.hpp"
#include "ECS/Component/Rectangle.hpp"
#include "ECS/Component/Collision.hpp"
#include "ECS/Component/Transform/Position.hpp"
#include "ECS/Component/Transform/Scale.hpp"
#include "ECS/Component/Tag.hpp"
#include "ECS/Component/Life.hpp"
#include "../../utils.hpp"

ColissionSystem::ColissionSystem(std::shared_ptr<ComponentManager> &components) : ASystem(components)
{
}

ColissionSystem::~ColissionSystem()
{
}

void ColissionSystem::update()
{
    std::vector<std::size_t> entityCollide;
    for (std::size_t i = 0; i < MAX_ENTITIES; i++)
    {
        if (!checkAvailableEntity(i))
            continue;
        Position &position = _componentManager->getComponent<Position>(i).value();
        Rectangle &rectangle = _componentManager->getComponent<Rectangle>(i).value();
        Collision &colission = _componentManager->getComponent<Collision>(i).value();
        Tag &tag = _componentManager->getComponent<Tag>(i).value();
        Life &life = _componentManager->getComponent<Life>(i).value();
        Scale &scale = _componentManager->getComponent<Scale>(i).value();
        if (!colission.isColide) {
            continue;
        }
        for (std::size_t j = 0; j < MAX_ENTITIES; j++)
        {
            if (!checkAvailableEntity(j))
                continue;
            if (contains(entityCollide, j) && j == i)
                continue;
            Position &positionTmp = _componentManager->getComponent<Position>(j).value();
            Rectangle &rectangleTmp = _componentManager->getComponent<Rectangle>(j).value();
            Collision &colissionTmp = _componentManager->getComponent<Collision>(j).value();
            Tag &tagTmp = _componentManager->getComponent<Tag>(j).value();
            Life &lifeTmp = _componentManager->getComponent<Life>(j).value();
            Scale &scaleTmp = _componentManager->getComponent<Scale>(j).value();
            if (!colissionTmp.isColide)
                continue;
            if (positionTmp.x < position.x + (rectangle.width * scale.scaleX) &&
                positionTmp.x + (rectangleTmp.width * scaleTmp.scaleX) > position.x &&
                positionTmp.y < position.y + (rectangle.height * scale.scaleY) &&
                (rectangleTmp.height * scaleTmp.scaleY) + positionTmp.y > position.y)
            {
                entityCollide.push_back(i);
                if (contains(tag.type, TagType::PLAYER) && contains(tagTmp.type, TagType::ENNEMY))
                {
                    life.health -= 100;
                }
                if (contains(tag.type, TagType::PLAYER) && (contains(tagTmp.type, TagType::BULLET) && contains(tagTmp.type, TagType::ENNEMY)))
                {
                    life.health -= 25;
                    lifeTmp.health = 0;
                }
                if (contains(tag.type, TagType::ENNEMY) && (contains(tagTmp.type, TagType::BULLET) && contains(tagTmp.type, TagType::PLAYER)))
                {
                    life.health -= 100;
                    lifeTmp.health = 0;
                }
            }
        }
    }
}

bool ColissionSystem::checkAvailableEntity(std::size_t entity) const
{
    const auto &rectangle = _componentManager->getComponentsList<Rectangle>();
    const auto &colision = _componentManager->getComponentsList<Collision>();
    const auto &position = _componentManager->getComponentsList<Position>();
    const auto &tag = _componentManager->getComponentsList<Tag>();
    const auto &life = _componentManager->getComponentsList<Life>();
    return rectangle[entity].has_value() && colision[entity].has_value() &&
        position[entity].has_value() && tag[entity].has_value() && life[entity].has_value();

}
