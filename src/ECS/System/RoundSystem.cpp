/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** RoundSystem
*/

#include "RoundSystem.hpp"
#include "ECS/Component/Game.hpp"
#include "ECS/Component/Tag.hpp"
#include "../../utils.hpp"

RoundSystem::RoundSystem(const std::shared_ptr<ComponentManager> &components, const std::shared_ptr<EntityManager> &entityManager) : ASystem(components, entityManager)
{
}

RoundSystem::~RoundSystem()
{
}

void RoundSystem::update()
{
    const auto &entities = _entityManager->getCurrentEntities();
    std::size_t id;
    int nbEnnemies = 0;
    auto &tags = _componentManager->getComponentsList<Tag>();
    auto &games = _componentManager->getComponentsList<Game>();

    for (const auto &currentEntity : entities)
    {
        currentEntity >> id;
        if (!checkAvailableEntityEnnemy(id))
        {
            continue;
        }
        Tag &tag = tags[currentEntity].value();
        if (contains(tag.type, TagType::ENNEMY) && !contains(tag.type, TagType::BULLET))
        {
            nbEnnemies++;
        }
    }
    for (const auto &currentEntity : entities)
    {
        currentEntity >> id;
        if (!checkAvailableEntity(id))
        {
            continue;
        }
        Game &game = games[currentEntity].value();
        if (nbEnnemies != game.nbEnnemies) {
            game.score += 10 * (abs(nbEnnemies - game.nbEnnemies));
        }
        game.nbEnnemies = nbEnnemies;
        if (nbEnnemies == 0) {
            game.round += 1;
            game.nbEnnemies = 5;
        }
    }
}

bool RoundSystem::checkAvailableEntity(size_t entity) const
{
    const auto &game = _componentManager->getComponentsList<Game>();

    return game[entity].has_value();
}

bool RoundSystem::checkAvailableEntityEnnemy(std::size_t entity) const
{
    const auto &tag = _componentManager->getComponentsList<Tag>();

    return tag[entity].has_value();
}
