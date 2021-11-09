/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#include "ASystem.hpp"

ASystem::ASystem(std::shared_ptr<ComponentsMap_t> &components): _components(std::move(components))
{

}

const Signature &ASystem::getSignature() const
{
    return _signature;
}

void ASystem::setSignature(const Signature &signature)
{
    _signature = signature;
}
