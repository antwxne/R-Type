/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** ShootSystem
*/

#include "ShootSystem.hpp"

ShootSystem::ShootSystem(const std::shared_ptr<ComponentManager> &components, const std::shared_ptr<EntityManager> &entityManager) : ASystem(components, entityManager)
{
}

ShootSystem::~ShootSystem()
{
}

void ShootSystem::update()
{
}

void ShootSystem::shoot(const std::size_t &entity)
{
    if (!checkAvailableEntity(entity))
        return;
    Firerate &firerate = _componentManager->getComponent<Firerate>(entity).value();
    float elapsed = firerate.clock.getElapsedTime().asSeconds();

    if (elapsed < firerate.delay) {
        std::cout << "WAIT !" << std::endl;
        return;
    }
    std::cout << "PAN PAN PAN !" << std::endl;
    firerate.clock.restart();
    //Create entity Bullet
}

bool ShootSystem::checkAvailableEntity(std::size_t entity) const
{
    const auto &firerate = _componentManager->getComponentsList<Firerate>();
    const auto &tag = _componentManager->getComponentsList<Tag>();

    if (!firerate[entity].has_value() || !tag[entity].has_value())
        return false;
    if (!contains(_componentManager->getComponent<Tag>(entity).value().type, TagType::PLAYER))
        return false;
    return true;
}