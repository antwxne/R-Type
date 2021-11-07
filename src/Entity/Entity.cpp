/*
** EPITECH PROJECT, 2021
** Boostrap
** File description:
** Entity
*/

#include "Entity.hpp"

Entity::Entity(size_t size) : _size(size)
{
}

Entity::~Entity()
{
}

void Entity::operator>>(size_t &object) const
{
    object = _size;
}

bool Entity::operator<(size_t size) const
{
    return size > _size;
}

bool Entity::operator==(const Entity &entity) const
{
    size_t value;

    entity >> value;

    return value == _size;
}

std::ostream& operator<<(std::ostream& os, const Entity& entity)
{
    size_t id;
    entity >> id;
    os << id;
    return os;
}