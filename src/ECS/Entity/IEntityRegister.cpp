/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#include "IEntityRegister.hpp"

IEntityRegister::IEntityRegister(): _entity(0)
{
}

const Entity &IEntityRegister::getEntity() const
{
    return _entity;
}

size_t IEntityRegister::getEntityValue() const
{
    size_t entity;

    _entity >> entity;

    return entity;
}