/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#include "IEntityRegister.hpp"

IEntityRegister::IEntityRegister(): _entity(0)
{
    _pos = Position{0, 0};
}

const Entity &IEntityRegister::getEntity() const
{
    return _entity;
}

void IEntityRegister::setPosition(const Position &pos)
{
    _pos = pos;
}