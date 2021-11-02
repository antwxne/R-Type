/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** EntityManager
*/

#ifndef ENTITYMANAGER_HPP_
#define ENTITYMANAGER_HPP_

#include "Entity.hpp"
#include <queue>
#include "rtype.h"
#include <unordered_map>

class EntityManager {
    public:
        EntityManager();
        ~EntityManager();
        Entity create();
        void destroy(Entity entity);
        void EntityManager::SetSignature(Entity entity, Signature signature);
        Signature GetSignature(Entity entity);
        
    private:
        std::queue<Entity> _avaiableEntities;
        std::unordered_map<Entity, Signature, EntityCompare> _entitiesSignature;
};

class EntityCompare
{
    bool operator()(const Entity&e1, const Entity&e2)
    {
        size_t id1, id2;

        e1 >> id1;
        e2 >> id2;
        return id1 < id2;
    }
};

#endif /* !ENTITYMANAGER_HPP_ */
