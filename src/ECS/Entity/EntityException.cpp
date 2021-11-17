/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#include "EntityException.hpp"

EntityException::EntityException(const Entity &entity,
    const std::string &message
)
{
    entity >> _id;
    _message = message;
}

const char *EntityException::what() const noexcept
{
    return std::string("Entity " + std::to_string(_id) + ": " + _message).c_str();
}