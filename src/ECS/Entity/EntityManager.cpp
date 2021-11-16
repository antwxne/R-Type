/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** EntityManager
*/

#include <iostream>

#include "EntityException.hpp"
#include "EntityManager.hpp"


EntityManager::EntityManager(std::shared_ptr<ComponentManager> &components) : _componentManager(std::move(components))
{
    for (size_t i = 0; i < MAX_ENTITIES; i++)
    {
	    _avaiableEntities.push(Entity(i));
    }
}

Entity EntityManager::create()
{
    Entity id = _avaiableEntities.front();

    _avaiableEntities.pop();

    return id;
}


void EntityManager::destroy(const Entity &entity)
{
    std::size_t index;

    entity >> index;
    if (!_entitiesSignature[index].has_value())
    {
        throw EntityException(entity, "can't destroy, entity doesn't exist.");
    }
    _entitiesSignature[index] = std::nullopt;
    _avaiableEntities.push(entity);
}

void EntityManager::setSignature(const Entity &entity, const Signature &signature)
{
    std::size_t index;

    entity >> index;
	if (_entitiesSignature[index].has_value())
    {
        throw EntityException(entity, "can't set signature, entity already have a signature.");
        return;
    }
	_entitiesSignature[index] = signature;
}

Signature &EntityManager::getSignature(const Entity &entity)
{
    std::size_t index;

    entity >> index;
	if (!_entitiesSignature[index].has_value())
    {
        throw EntityException(entity, "can't get signature, entity already have a signature.");
    }
    return _entitiesSignature[index].value();
}

const Signature &EntityManager::getSignature(const Entity &entity) const
{
    std::size_t index;

    entity >> index;
    if (!_entitiesSignature[index].has_value())
    {
        throw EntityException(entity, "can't get signature, entity already have a signature.");
    }
    return _entitiesSignature[index].value();
}
