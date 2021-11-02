/*
** EPITECH PROJECT, 2021
** Boostrap
** File description:
** Entity
*/

#include "Entity.hpp"
#include <any>
#include <iostream>

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

bool Entity::operator<(size_t size)
{
    return size > _size;
}
