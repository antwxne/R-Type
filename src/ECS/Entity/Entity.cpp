/*
** EPITECH PROJECT, 2021
** Boostrap
** File description:
** Entity
*/

#include "Entity.hpp"

Entity::Entity(std::size_t size) : _size(size)
{
}

Entity::~Entity()
{
}

void Entity::operator>>(std::size_t &object) const
{
    object = _size;
}

bool Entity::operator<(std::size_t size) const
{
    return size > _size;
}

bool Entity::operator==(const Entity &entity) const
{
    std::size_t value;

    entity >> value;

    return value == _size;
}

std::ostream& operator<<(std::ostream& os, const Entity& entity)
{
    std::size_t id;
    entity >> id;
    os << id;
    return os;
}