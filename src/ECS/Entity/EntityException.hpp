/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#ifndef RTYPE_ENTITYEXCEPTION_HPP
#define RTYPE_ENTITYEXCEPTION_HPP

#include <exception>
#include <string>

#include "Entity.hpp"

class EntityException : public std::exception {
public:
    EntityException(const Entity &entity, const std::string &message = "error");

    const char *what() const noexcept override;

private:
    std::size_t _id;
    std::string _message;
};

#endif //RTYPE_ENTITYEXCEPTION_HPP
