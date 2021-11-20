/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#include "SoundEntity.hpp"

SoundEntity::SoundEntity(const SoundType &sound): _sound(sound)
{

}

void SoundEntity::create(
    const std::shared_ptr<ComponentManager> &componentManager,
    const std::shared_ptr<EntityManager> &entityManager
)
{
    std::shared_ptr<sf::Sound> sound = std::make_shared<sf::Sound>();
    _entity = entityManager->create();
    componentManager->subToComponent(_entity, SfmlSound{false, _sound, sound});
}
