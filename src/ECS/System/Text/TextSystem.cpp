/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** TextSystem
*/

#include "TextSystem.hpp"

TextSystem::TextSystem(const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManager) : ASystem(componentManager, entityManager)
{
}

TextSystem::~TextSystem()
{
}

void TextSystem::update()
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

bool TextSystem::checkAvailableEntity(size_t entity) const
{
    return false;
}


void TextSystem::draw(const std::size_t entity)
{

}