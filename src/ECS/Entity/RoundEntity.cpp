/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** RoundEntity
*/

#include "RoundEntity.hpp"

RoundEntity::RoundEntity(const Round &round) : IEntityRegister()
{
    _round = round;
}

RoundEntity::~RoundEntity()
{
}

void RoundEntity::create(const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManager)
{
    _entity = entityManager->create();

    componentManager->subToComponent(_entity, _round);
}
