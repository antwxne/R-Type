/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** EntityManager
*/

#ifndef ENTITYMANAGER_HPP_
#define ENTITYMANAGER_HPP_

#include <queue>
#include <array>
#include <optional>

#include "rtype.h"
#include "Entity.hpp"

class EntityManager {
public:
    EntityManager();
    ~EntityManager() = default;
    Entity create();
    void destroy(const Entity &entity);
    const std::vector<Entity> &getCurrentEntities() const;

private:
    std::queue<Entity> _availableEntities;
    std::vector<Entity> _currentEntities;
};

#endif /* !ENTITYMANAGER_HPP_ */