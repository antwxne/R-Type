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

ColissionSystem::ColissionSystem(std::shared_ptr<ComponentManager::ComponentsMap_t> &components) : ASystem(components)
{
    _usedComponents.push_back(typeid(Rectangle).name());
    _usedComponents.push_back(typeid(Colission).name());
    _usedComponents.push_back(typeid(Position).name());
}

ColissionSystem::~ColissionSystem()
{
}

void ColissionSystem::update()
{
    for (std::size_t i = 0; i < MAX_ENTITIES; i++)
    {
        if (!checkAvailableEntity(i))
            continue;
        Position &position = _componentManager->getComponent<Position>(i).value();
        Rectangle &rectangle = _componentManager->getComponent<Rectangle>(i).value();
        Colission &colission = _componentManager->getComponent<Colission>(i).value();

        for (std::size_t j = 0; j < MAX_ENTITIES; j++)
        {
            if (!checkAvailableEntity(j))
                continue;
            Position &positionTmp = _componentManager->getComponent<Position>(j).value();
            Rectangle &rectangleTmp = _componentManager->getComponent<Rectangle>(j).value();
            Colission &colissionTmp = _componentManager->getComponent<Colission>(j).value();
            if (positionTmp.x < position.x + rectangle.width &&
                positionTmp.x + rectangleTmp.width > position.x &&
                positionTmp.y < position.y + rectangle.height &&
                rectangleTmp.height + positionTmp.y > position.y)
            {
                std::cout << "colission detecté!" << std::endl;*
            }
        }
    }