/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** EntityManager
*/

#include "EntityManager.hpp"
#include <iostream>

EntityManager::EntityManager()
{
    for (size_t i = 0; i < MAX_ENTITIES; i++)
    {
	    _avaiableEntities.push(Entity(i));
    }
}

EntityManager::~EntityManager()
{
}

Entity EntityManager::create()
{
    Entity id = _avaiableEntities.front();

    _avaiableEntities.pop();

    return id;
}


void EntityManager::destroy(Entity entity)
{
    if (entity < MAX_ENTITIES)
    {
        std::cout << "Cannot destroy entity " << entity << std::endl;
        return;
    }

    _avaiableEntities.push(entity);
}

void EntityManager::SetSignature(Entity entity, Signature signature)
{
	if (entity < MAX_ENTITIES)
    {
        std::cout << "Cannot destroy entity " << entity << std::endl;
        return;
    }
    
	_entitiesSignature[entity] = signature;
}

Signature EntityManager::GetSignature(Entity entity)
{

	if (_entitiesSignature.find(entity) == _entitiesSignature.end())
    {
        Signature signature = Signature(0);
        return signature;
    }
    return _entitiesSignature[entity];
}