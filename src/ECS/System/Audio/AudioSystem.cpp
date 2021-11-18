/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** AudioSystem
*/

#include "AudioSystem.hpp"

AudioSystem::AudioSystem(
    const std::shared_ptr<ComponentManager> &componentManager,
    const std::shared_ptr<EntityManager> &entityManager
) : ASystem(componentManager, entityManager)
{
}

AudioSystem::~AudioSystem()
{
}