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

DrawSystem::DrawSystem(std::shared_ptr<ComponentManager::ComponentsMap_t> &components) : ASystem(components)
{
    _usedComponents.push_back(typeid(Position));
    _usedComponents.push_back(typeid(Texture));
    _usedComponents.push_back(typeid(Scale));
    _usedComponents.push_back(typeid(Rotate));
    _usedComponents.push_back(typeid(Color));
}

DrawSystem::~DrawSystem()
{
}

void DrawSystem::update()
{
    for (std::size_t i = 0; i < MAX_ENTITIES; i++)
    {
        if (checkAvaiableEntity(i))
        {
            draw(i);
        }
    }
}


void DrawSystem::draw(const std::size_t entity)
{

}