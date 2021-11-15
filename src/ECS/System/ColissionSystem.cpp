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
    _usedComponents.push_back(typeid(Rectangle));
    _usedComponents.push_back(typeid(Colission));
    _usedComponents.push_back(typeid(Position));
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
        Position &position = std::any_cast<Position &>(_components->at(typeid(Position))->getData(i).value());
        Rectangle &rectangle = std::any_cast<Rectangle &>(_components->at(typeid(Rectangle))->getData(i).value());
        Colission &colission = std::any_cast<Colission &>(_components->at(typeid(Colission))->getData(i).value());

        for (std::size_t j = 0; j < MAX_ENTITIES; j++)
        {
            if (!checkAvailableEntity(j))
                continue;
            Position &positionTmp = std::any_cast<Position &>(_components->at(typeid(Position))->getData(j).value());
            Rectangle &rectangleTmp = std::any_cast<Rectangle &>(_components->at(typeid(Rectangle))->getData(j).value());
            Colission &colissionTmp = std::any_cast<Colission &>(_components->at(typeid(Colission))->getData(j).value());
            if (positionTmp.x < position.x + rectangle.width &&
                positionTmp.x + rectangleTmp.width > position.x &&
                positionTmp.y < position.y + rectangle.height &&
                rectangleTmp.height + positionTmp.y > position.y)
            {
                std::cout << "colission detecté!" << std::endl;*
            }
        }
    }