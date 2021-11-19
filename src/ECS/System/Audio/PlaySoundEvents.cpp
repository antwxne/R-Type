/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#include "PlaySoundEvents.hpp"
#include "ECS/component.hpp"

PlaySoundEvents::PlaySoundEvents(
    const std::shared_ptr<ComponentManager> &components,
    const std::shared_ptr<EntityManager> &entityManager
) : ASystem(components, entityManager)
{

}

void PlaySoundEvents::update()
{
    const auto &entities = _entityManager->getCurrentEntities();
    auto &sounds = _componentManager->getComponentsList<SfmlSound>();

    for (const auto &entity : entities) {
        auto &currentSound = sounds[entity];
        if (currentSound.has_value() && currentSound.value().play) {
            std::cout << "play"<< std::endl;
            currentSound.value().sound.play();
            currentSound.value().play = false;
        }
    }
}

bool PlaySoundEvents::checkAvailableEntity(std::size_t entity) const
{
    return true;
}
