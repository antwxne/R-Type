/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#include <iostream>

#include "ECS/component.hpp"
#include "EventCallback.hpp"
#include "../../Entity/BulletEntity.hpp"
#include "../../Component/Tag.hpp"
#include "../../../utils.hpp"

void EventCallback::changeAccelerationUP(std::shared_ptr<ComponentManager> componentManager,
    const size_t &entity, std::shared_ptr<EntityManager> entityManager
)
{
    auto &currentAcceleration = componentManager->getComponent<Acceleration>(entity);
    auto &currentSpeed = componentManager->getComponent<Speed>(entity);

    if (!currentAcceleration.has_value() || !currentSpeed.has_value()) {
        return;
    }
    currentAcceleration.value().x = 0;
    currentAcceleration.value().y = -1;
    currentSpeed.value().speed = 5;
}

void EventCallback::changeAccelerationDOWN(
    std::shared_ptr<ComponentManager> componentManager, const size_t &entity,
    std::shared_ptr<EntityManager> entityManager
)
{
    auto &currentAcceleration = componentManager->getComponent<Acceleration>(entity);
    auto &currentSpeed = componentManager->getComponent<Speed>(entity);

    if (!currentAcceleration.has_value() || !currentSpeed.has_value()) {
        return;
    }
    currentAcceleration.value().x = 0;
    currentAcceleration.value().y = 1;
    currentSpeed.value().speed = 5;
}

void EventCallback::changeAccelerationLEFT(
    std::shared_ptr<ComponentManager> componentManager, const size_t &entity,
    std::shared_ptr<EntityManager> entityManager
)
{
    auto &currentAcceleration = componentManager->getComponent<Acceleration>(entity);
    auto &currentSpeed = componentManager->getComponent<Speed>(entity);

    if (!currentAcceleration.has_value() || !currentSpeed.has_value()) {
        return;
    }
    currentAcceleration.value().x = -1;
    currentAcceleration.value().y = 0;
    currentSpeed.value().speed = 5;
}

void EventCallback::changeAccelerationRIGHT(
    std::shared_ptr<ComponentManager> componentManager, const size_t &entity,
    std::shared_ptr<EntityManager> entityManager
)
{
    auto &currentAcceleration = componentManager->getComponent<Acceleration>(entity);
    auto &currentSpeed = componentManager->getComponent<Speed>(entity);

    if (!currentAcceleration.has_value() || !currentSpeed.has_value()) {
        return;
    }
    currentAcceleration.value().x = 1;
    currentAcceleration.value().y = 0;
    currentSpeed.value().speed = 5;
}

void EventCallback::shoot(
    std::shared_ptr<ComponentManager> componentManager, const size_t &entity,
    std::shared_ptr<EntityManager> entityManager
)
{
    auto &currentFirerate = componentManager->getComponent<Firerate>(entity);
    auto &currentPostion = componentManager->getComponent<Position>(entity);
    auto &currentTag = componentManager->getComponent<Tag>(entity);
    if (!currentFirerate.has_value() || !currentPostion.has_value() || !currentTag.has_value()) {
        return;
    }
    float elapsed = currentFirerate.value().clock.getElapsedTime().asSeconds();
    Position posBullet = currentPostion.value();
    Tag &tag = currentTag.value();
    bool isFriend = true;

    if (elapsed < currentFirerate.value().delay) {
        std::cout << "WAIT !" << std::endl;
        return;
    }
    if (contains(tag.type, TagType::ENNEMY)) {
        posBullet.x -= 130;
        posBullet.y += 20;
        isFriend = false;
    }
    else {
        posBullet.x += 130;
        posBullet.y += 20;
    }
    BulletEntity _be(posBullet, isFriend);
    _be.create(componentManager, entityManager);
    currentFirerate.value().clock.restart();
}