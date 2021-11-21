/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlSound
*/

#include "SfmlSoundSystem.hpp"
#include "ECS/Component/SfmlSound.hpp"

SfmlSoundSystem::SfmlSoundSystem(const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManager)
: ASystem(componentManager, entityManager)
{
}

SfmlSoundSystem::~SfmlSoundSystem()
{
}

void SfmlSoundSystem::update()
{
    auto &sounds = _componentManager->getComponentsList<SfmlSound>();

    for (std::size_t i = 0; i < MAX_ENTITIES; i++)
    {
        if (!checkAvailableEntity(i))
            continue;
        auto &sound = sounds[i].value();
        if (sound.sound->getBuffer() == nullptr)
        {
            std::shared_ptr<sf::SoundBuffer> buffer = _handler.getSoundBuffer(sound.soundtype);
            if (buffer)
                sound.sound->setBuffer(*buffer);
        }
        if (sound.play == false && sound.sound)
        {
            sound.sound->play();
            sound.play = true;
        }
    }
}

bool SfmlSoundSystem::checkAvailableEntity(const std::size_t entity) const
{
    const auto &sound = _componentManager->getComponentsList<SfmlSound>();

    return sound[entity].has_value();
}
