/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#include "ECS.hpp"
#include "utils.hpp"
#include "ECS/System/EventSystem/EventSystem.hpp"

Entity ECS::createEntity()
{
    return _entityManager->create();
}

ECS::ECS()
{
    _entityManager = std::make_shared<EntityManager>();
    _componentManager = std::make_shared<ComponentManager>();
    _systemManager = std::make_unique<SystemManager>(_componentManager,
        _entityManager);
}

void ECS::destroyEntity(const Entity &entity)
{
    _entityManager->destroy(entity);
    std::cout << "destroyEntity  == " << entity << std::endl;

}

void ECS::garbageCollector(std::vector<RaisedEvent> &raisedEvent)
{
    try {
        const auto &lifes = _componentManager->getComponentsList<Life>();
        const auto &positions = _componentManager->getComponentsList<Position>();
        const auto &hitboxes = _componentManager->getComponentsList<Rectangle>();
        const auto &tags = _componentManager->getComponentsList<Tag>();
        const auto &sounds = _componentManager->getComponentsList<SfmlSound>();

        std::size_t idx;
        const auto &currentEntities = _entityManager->getCurrentEntities();

        for (const auto &entity: currentEntities) {
            entity >> idx;
            if (!isAlive(lifes[idx])) {
                raisedEvent.push_back(RaisedEvent::PLAYER_DIED);
                destroyEntity(idx);
            }
            if (!isInScreen(positions[idx], hitboxes[idx], tags[idx])) {
                destroyEntity(idx);
            }
        }
    } catch (...) {
    }
}

bool ECS::isAlive(const std::optional<Life> &lifeComponent) const
{
    if (!lifeComponent.has_value()) {
        return true;
    }
    return lifeComponent.value().health > 0;
}

bool ECS::isInScreen(const std::optional<Position> &position,
    const std::optional<Rectangle> &hitbox, const std::optional<Tag> &bullet
) const
{
    if (!position.has_value() || !hitbox.has_value() || !bullet.has_value() ||
        !contains<TagType>(bullet.value().type, TagType::BULLET)) {
        return true;
    }
    std::pair<float, float> windowSizeMax = {2000, 1200};
    std::pair<float, float> windowSizeMin = {-200, -200};

    auto plop = position.value().x < windowSizeMin.first ||
        position.value().y < windowSizeMin.second ||
        position.value().x + static_cast<float>(hitbox.value().width) >
            windowSizeMax.first ||
        position.value().y + static_cast<float>(hitbox.value().height) >
            windowSizeMax.second;
    return !plop;
}

void ECS::destroyEntity(const size_t &entity)
{
    destroyEntity(Entity(entity));
}

const std::shared_ptr<EntityManager> &ECS::getEntityManager() const
{
    return _entityManager;
}

const std::shared_ptr<ComponentManager> &ECS::getComponentManager() const
{
    return _componentManager;
}

const std::unique_ptr<SystemManager> &ECS::getSystemManager() const
{
    return _systemManager;
}

bool ECS::isADeadSound(const std::optional<Tag> &tag,
    const std::optional<SfmlSound> &sound
)
{
    const std::vector<TagType> types = {TagType::PLAYER, TagType::BULLET,
        TagType::ENNEMY};

    if (!tag.has_value() || !sound.has_value()) {
        return false;
    }
    for (const auto &type: types) {
        if (contains<TagType>(tag.value().type, type)) {
            std::cout << "2" << std::endl;
            return false;
        }
    }
    if (contains<TagType>(tag.value().type, TagType::SOUND) &&
        !sound.value().play) {
        std::cout << "3" << std::endl;
        return false;
    }

    return false;
}