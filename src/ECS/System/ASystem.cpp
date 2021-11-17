/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#include "ASystem.hpp"

#include "ECS/component.hpp"

ASystem::ASystem(std::shared_ptr<ComponentManager> components): _componentManager(std::move(components))
{

}