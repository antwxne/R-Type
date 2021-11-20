/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/


#include "ECS/component.hpp"
#include "EventCallback.hpp"
#include "ECS/Entity/BulletEntity.hpp"
#include "ECS/Component/Tag.hpp"
#include "utils.hpp"
#include "ECS/Entity/SoundEntity.hpp"

void EventCallback::changeAccelerationUP(const std::shared_ptr<ComponentManager> &componentManager,
    const std::size_t &entity, const std::shared_ptr<EntityManager> &entityManager,
    std::vector<RaisedEvent> &raisedEvents
)
{
    auto &currentAcceleration = componentManager->getComponent<Acceleration>(
        entity);
    auto &currentSpeed = componentManager->getComponent<Speed>(entity);

    if (!currentAcceleration.has_value() || !currentSpeed.has_value()) {
        return;
    }
    currentAcceleration.value().x = 0;
    currentAcceleration.value().y = -1;
    currentSpeed.value().speed = 12;
}

void EventCallback::changeAccelerationDOWN(
    const std::shared_ptr<ComponentManager> &componentManager,
    const std::size_t &entity, const std::shared_ptr<EntityManager> &entityManager,
    std::vector<RaisedEvent> &raisedEvents
)
{
    auto &currentAcceleration = componentManager->getComponent<Acceleration>(
        entity);
    auto &currentSpeed = componentManager->getComponent<Speed>(entity);

    if (!currentAcceleration.has_value() || !currentSpeed.has_value()) {
        return;
    }
    currentAcceleration.value().x = 0;
    currentAcceleration.value().y = 1;
    currentSpeed.value().speed = 12;
}

void EventCallback::changeAccelerationLEFT(
    const std::shared_ptr<ComponentManager> &componentManager,
    const std::size_t &entity, const std::shared_ptr<EntityManager> &entityManager,
    std::vector<RaisedEvent> &raisedEventss
)
{
    auto &currentAcceleration = componentManager->getComponent<Acceleration>(
        entity);
    auto &currentSpeed = componentManager->getComponent<Speed>(entity);

    if (!currentAcceleration.has_value() || !currentSpeed.has_value()) {
        return;
    }
    currentAcceleration.value().x = -1;
    currentAcceleration.value().y = 0;
    currentSpeed.value().speed = 12;
}

void EventCallback::changeAccelerationRIGHT(
    const std::shared_ptr<ComponentManager> &componentManager,
    const std::size_t &entity, const std::shared_ptr<EntityManager> &entityManager,
    std::vector<RaisedEvent> &raisedEvents
)
{
    auto &currentAcceleration = componentManager->getComponent<Acceleration>(
        entity);
    auto &currentSpeed = componentManager->getComponent<Speed>(entity);

    if (!currentAcceleration.has_value() || !currentSpeed.has_value()) {
        return;
    }
    currentAcceleration.value().x = 1;
    currentAcceleration.value().y = 0;
    currentSpeed.value().speed = 12;
}

void EventCallback::shoot( const std::shared_ptr<ComponentManager> &componentManager,
    const std::size_t &entity, const std::shared_ptr<EntityManager> &entityManager,
    std::vector<RaisedEvent> &raisedEvents
)
{
    std::cout << "SHoot start\n";
    auto &currentFirerate = componentManager->getComponent<Firerate>(entity);
    auto &currentPostion = componentManager->getComponent<Position>(entity);
    auto &currentTag = componentManager->getComponent<Tag>(entity);

    std::cout << "After init\n";
    if (!currentFirerate.has_value() || !currentPostion.has_value() ||
        !currentTag.has_value()) {
        return;
    }

    float elapsed = currentFirerate.value().clock.getElapsedTime().asSeconds();
    Position posBullet = currentPostion.value();
    Tag &tag = currentTag.value();
    bool isFriend = true;

    if (elapsed < currentFirerate.value().delay) {
        return;
    }
    if (contains(tag.type, TagType::ENNEMY)) {
        posBullet.x -= 130;
        posBullet.y += 20;
        isFriend = false;
    } else {
        posBullet.x += 130;
        posBullet.y += 20;
    }
    std::cout << "After cheange\n";
    BulletEntity _be(posBullet, isFriend);
    _be.create(componentManager, entityManager);
    std::cout << "After create\n";
    currentFirerate.value().clock.restart();
    raisedEvents.emplace_back(RaisedEvent::SHOT);
}


void EventCallback::explosionSound(
    const std::shared_ptr<ComponentManager> &componentManager,
    const std::size_t &entity, const std::shared_ptr<EntityManager> &entityManager,
    std::vector<RaisedEvent> &raisedEvents
)
{
    std::cout << "EXPLOSION" << std::endl;
    std::cout << "nb entites avant == " << entityManager->getCurrentEntities().size() << std::endl;


    SoundEntity newEntity("./assets/sound/explosion.ogg");

    newEntity.create(componentManager, entityManager);
    std::cout << "nb entites apres == " << entityManager->getCurrentEntities().size() << std::endl;

}
