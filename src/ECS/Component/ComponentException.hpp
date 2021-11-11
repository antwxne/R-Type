/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#ifndef RTYPE_COMPONENTEXCEPTION_HPP
#define RTYPE_COMPONENTEXCEPTION_HPP

#include <exception>

#include "ECS/Entity/Entity.hpp"

template<typename T>
class ComponentException : public std::exception {
public:
    ComponentException(const Entity &entity, const T &component, const std::string &message = "error");

    const char *what() const noexcept override;

private:
    std::size_t _id;
    std::string _message;
    T _component;
};

template<typename T>
ComponentException<T>::ComponentException(const Entity &entity,
    const T &component, const std::string &message
)
{
    entity >> _id;
    _component = component;
    _message = message;
}

template<typename T>
const char *ComponentException<T>::what() const noexcept
{
    return std::string("Entity " + std::to_string(_id) + "<component: " +
    typeid(_component).name() + " >: " + _message).c_str();
}

#endif //RTYPE_COMPONENTEXCEPTION_HPP
