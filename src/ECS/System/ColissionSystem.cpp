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
#include "ECS/Component/Bonus.hpp"
#include "ECS/Component/Firerate.hpp"
#include "../../utils.hpp"

ColissionSystem::ColissionSystem(
    const std::shared_ptr<ComponentManager> &components,
    const std::shared_ptr<EntityManager> &entityManager) : ASystem(components, entityManager)
{
}

ColissionSystem::~ColissionSystem()
{
}

void ColissionSystem::update()
{
    std::vector<std::size_t> entityCollide;
    auto &positions = _componentManager->getComponentsList<Position>();
    auto &rectangles = _componentManager->getComponentsList<Rectangle>();
    auto &colissions = _componentManager->getComponentsList<Collision>();
    auto &tags = _componentManager->getComponentsList<Tag>();
    auto &lifes = _componentManager->getComponentsList<Life>();
    auto &scales = _componentManager->getComponentsList<Scale>();
    const auto &entities = _entityManager->getCurrentEntities();
    std::size_t id;
    std::size_t otherId;

    for (const auto &currentEntity : entities)
    {
        currentEntity >> id;
        if (!checkAvailableEntity(id))
        {
            continue;
        }

        Position &position = positions[currentEntity].value();
        Rectangle &rectangle = rectangles[currentEntity].value();
        Collision &colission = colissions[currentEntity].value();
        Tag &tag = tags[currentEntity].value();
        Life &life = lifes[currentEntity].value();
        Scale &scale = scales[currentEntity].value();

        if (!colission.isColide)
        {
            continue;
        }
        for (const auto &otherEntity : entities)
        {
            try
            {
                otherEntity >> otherId;
                if (!checkAvailableEntity(id))
                {
                    continue;
                }
                if (contains(entityCollide, otherId) || id == otherId)
                    continue;
                Position &positionTmp = positions[otherEntity].value();
                Rectangle &rectangleTmp = rectangles[otherEntity].value();
                Collision &colissionTmp = colissions[otherEntity].value();
                Tag &tagTmp = tags[otherEntity].value();
                Life &lifeTmp = lifes[otherEntity].value();
                Scale &scaleTmp = scales[otherEntity].value();
                if (!colissionTmp.isColide)
                    continue;
                if (position.x < positionTmp.x + rectangleTmp.width &&
                    position.x + rectangle.width > positionTmp.x &&
                    position.y < positionTmp.y + rectangleTmp.height &&
                    rectangle.height + position.y > positionTmp.y)
                {
                    entityCollide.push_back(id);
                    if (contains(tagTmp.type, TagType::PLAYER) &&
                        contains(tag.type, TagType::POWERUP))
                    {
                        life.health = 0;
                        handleBonusCollision(id, otherId);
                    }
                    if (contains(tag.type, TagType::PLAYER) &&
                        contains(tagTmp.type, TagType::ENEMY))
                    {
                        life.health = -25;
                    }
                    if (contains(tag.type, TagType::PLAYER) &&
                        (contains(tagTmp.type, TagType::BULLET) &&
                         contains(tagTmp.type, TagType::ENEMY)))
                    {
                        life.health -= 25;
                        lifeTmp.health = 0;
                    }
                    if (contains(tag.type, TagType::ENEMY) &&
                        (contains(tagTmp.type, TagType::BULLET) &&
                         contains(tagTmp.type, TagType::PLAYER)))
                    {
                        life.health -= 25;
                        lifeTmp.health = 0;
                    }
                }
            }
            catch (...)
            {
                continue;
            }
        }
    }
}

bool ColissionSystem::checkAvailableEntity(std::size_t entity) const
{
    const auto &rectangle = _componentManager->getComponentsList<Rectangle>();
    const auto &collision = _componentManager->getComponentsList<Collision>();
    const auto &position = _componentManager->getComponentsList<Position>();
    const auto &tag = _componentManager->getComponentsList<Tag>();
    const auto &life = _componentManager->getComponentsList<Life>();

    return rectangle[entity].has_value() && collision[entity].has_value() &&
           position[entity].has_value() && tag[entity].has_value() &&
           life[entity].has_value();
}


void ColissionSystem::handleBonusCollision(std::size_t entityPlayer, std::size_t entitybonus)
{
    auto &bonus = _componentManager->getComponentsList<Bonus>();
    auto &lifes = _componentManager->getComponentsList<Life>();
    auto &firerate = _componentManager->getComponentsList<Firerate>();

    if (!bonus[entitybonus].has_value())
        return;
    
    if (!lifes[entityPlayer].has_value() || firerate[entityPlayer].has_value())
        return;
    
    if (bonus[entitybonus].value().type == BonusType::HealBonus)
        lifes[entityPlayer].value().health += 100;
    else
        if (firerate[entityPlayer].value().delay > 150)
        {
            firerate[entityPlayer].value().delay -= 20;
        }

}