/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** DrawSystem
*/

#include "DrawSystem.hpp"
#include "../../Component/Transform/Position.hpp"
#include "../../Component/Texture.hpp"
#include "../../Component/Transform/Scale.hpp"
#include "../../Component/Transform/Rotate.hpp"
#include "../../Component/Color.hpp"

DrawSystem::DrawSystem(std::shared_ptr<ComponentManager> componentManager) : ASystem(componentManager)
{
}

DrawSystem::~DrawSystem()
{
}

void DrawSystem::update()
{
    for (std::size_t i = 0; i < MAX_ENTITIES; i++)
    {
        if (checkAvailableEntity(i))
        {
            draw(i);
        }
    }
}

bool DrawSystem::checkAvailableEntity(size_t entity) const
{
    return false;
}


void DrawSystem::draw(const std::size_t entity)
{

}