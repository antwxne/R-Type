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
