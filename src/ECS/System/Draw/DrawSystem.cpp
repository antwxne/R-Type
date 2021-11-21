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

DrawSystem::DrawSystem(const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManager) : ASystem(componentManager, entityManager)
{
}

DrawSystem::~DrawSystem()
{
}

void DrawSystem::update()
{
    const auto &entities = _entityManager->getCurrentEntities();
    std::size_t id;
    for (const auto &entity : entities)
    {
        entity >> id;
        if (checkAvailableEntity(id))
        {
            draw(id);
        }
    }
}

bool DrawSystem::checkAvailableEntity(std::size_t entity) const
{
    return false;
}


void DrawSystem::draw(const std::size_t entity)
{

}