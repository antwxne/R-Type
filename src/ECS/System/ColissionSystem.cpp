/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** ColissionSystem
*/

#include "ColissionSystem.hpp"
#include "../Component/Rectangle.hpp"
#include "../Component/Colission.hpp"
#include "../Component/Transform/Position.hpp"
#include "../Component/Tag.hpp"
#include "../Component/Life.hpp"
#include "../../utils.hpp"

ColissionSystem::ColissionSystem(std::shared_ptr<ComponentManager> &components) : ASystem(components)
{
    _usedComponents.push_back(typeid(Rectangle).name());
    _usedComponents.push_back(typeid(Colission).name());
    _usedComponents.push_back(typeid(Position).name());
    _usedComponents.push_back(typeid(Tag).name());
    _usedComponents.push_back(typeid(Life).name());
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
        Colission &colission = _componentManager->getComponent<Colission>(i).value();
        Tag &tag = _componentManager->getComponent<Tag>(i).value();
        Life &life = _componentManager->getComponent<Life>(i).value();
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
            Colission &colissionTmp = _componentManager->getComponent<Colission>(j).value();
            Tag &tagTmp = _componentManager->getComponent<Tag>(j).value();
            Life &lifeTmp = _componentManager->getComponent<Life>(j).value();
            if (!colissionTmp.isColide)
                continue;
            if (positionTmp.x < position.x + rectangle.width &&
                positionTmp.x + rectangleTmp.width > position.x &&
                positionTmp.y < position.y + rectangle.height &&
                rectangleTmp.height + positionTmp.y > position.y)
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