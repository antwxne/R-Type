/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** BonusSystem
*/

#include "BonusSystem.hpp"
#include "ECS/Component/Bonus.hpp"
#include "ECS/Entity/BonusEntity.hpp"

BonusSystem::BonusSystem(const std::shared_ptr<ComponentManager> &components, const std::shared_ptr<EntityManager> &entityManager)
: ASystem(components, entityManager)
{
}

BonusSystem::~BonusSystem()
{
}

void BonusSystem::update()
{
    auto &tags = _componentManager->getComponentsList<Bonus>();
    const auto &entities = _entityManager->getCurrentEntities();
    std::size_t id;
    int nbBonus = 0;

    for (const auto &entity : entities)
    {
        entity >> id;
        if (!checkAvailableEntity(id))
            continue;
        nbBonus++;
    }

    if (nbBonus < 3)
    {
        int bonusTypeRand = rand()% 2;
        BonusType type;
        if (bonusTypeRand == 0)
            type = BonusType::HealBonus;
        else
            type = BonusType::ShootSpeedBonus;

        int xPosRAnd = rand()%(1000-200 + 1) + 200;
        int yPosRand = rand()%(50-900 + 1) + 50;

        BonusEntity bonusEntity({(float)xPosRAnd,(float)yPosRand}, type);
        bonusEntity.create(_componentManager, _entityManager);
    }
}

bool BonusSystem::checkAvailableEntity(std::size_t entity) const
{
    const auto &bonus = _componentManager->getComponentsList<Bonus>();

    return bonus[entity].has_value();
}