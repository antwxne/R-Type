/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** EntityManager
*/

#include <algorithm>

#include "EntityException.hpp"
#include "EntityManager.hpp"


EntityManager::EntityManager()
{
    for (std::size_t i = 0; i < MAX_ENTITIES; i++)
    {
	    _availableEntities.push(Entity(i));
    }
}

Entity EntityManager::create()
{
    Entity id = _availableEntities.front();

    _availableEntities.pop();
    _currentEntities.push_back(id);
    return id;
}


void EntityManager::destroy(const Entity &entity)
{
    std::size_t index;

    entity >> index;
    _currentEntities.erase(std::remove_if(_currentEntities.begin(), _currentEntities.end(), [=](Entity &a){return a == entity;}), _currentEntities.end());
    _availableEntities.push(entity);
}

const std::vector<Entity> &EntityManager::getCurrentEntities() const
{
    return _currentEntities;
}
