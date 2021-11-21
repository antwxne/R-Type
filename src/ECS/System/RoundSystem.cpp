/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** RoundSystem
*/

#include "RoundSystem.hpp"
#include "ECS/Component/Round.hpp"
#include "ECS/Component/Tag.hpp"
#include "../../utils.hpp"
#include "ECS/Entity/EnemyEntity.hpp"
RoundSystem::RoundSystem(const std::shared_ptr<ComponentManager> &components, const std::shared_ptr<EntityManager> &entityManager) : ASystem(components, entityManager), _ee("./lib")
{
}

RoundSystem::~RoundSystem()
{
}

void RoundSystem::update()
{
    const auto &entities = _entityManager->getCurrentEntities();
    std::size_t id;
    int nbEnemies = 0;
    auto &tags = _componentManager->getComponentsList<Tag>();
    auto &rounds = _componentManager->getComponentsList<Round>();
    int nbRounds = 1;

    for (const auto &currentEntity : entities)
    {
        currentEntity >> id;
        if (!checkAvailableEntityEnemy(id))
        {
            continue;
        }
        Tag &tag = tags[currentEntity].value();
        if (contains(tag.type, TagType::ENEMY) && !contains(tag.type, TagType::BULLET))
        {
            nbEnemies++;
        }
    }
    for (const auto &currentEntity : entities)
    {
        currentEntity >> id;
        if (!checkAvailableEntity(id))
        {
            continue;
        }
        Round &round = rounds[currentEntity].value();
        if (nbEnemies != round.nbEnemies)
        {
            round.score += 10 * (abs(nbEnemies - round.nbEnemies));
        }
        round.nbEnemies = nbEnemies;
        if (nbEnemies == 0)
        {
            round.round += 1;
            nbRounds = round.round;
        }
    }
    if (nbEnemies == 0)
    {
        for (int i = 0; i < 5 + nbRounds; i++)
        {
            _ee.setPosition({1920, (static_cast<float>(200 * i))});
            _ee.create(_componentManager, _entityManager);
            //EnemyEntity enemy({1920, (static_cast<float>(200 * i))});
            //enemy.create(_componentManager, _entityManager);
        }
    }
}

bool RoundSystem::checkAvailableEntity(size_t entity) const
{
    const auto &round = _componentManager->getComponentsList<Round>();

    return round[entity].has_value();
}

bool RoundSystem::checkAvailableEntityEnemy(std::size_t entity) const
{
    const auto &tag = _componentManager->getComponentsList<Tag>();

    return tag[entity].has_value();
}
