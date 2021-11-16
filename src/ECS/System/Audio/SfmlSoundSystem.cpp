/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlSound
*/

#include "SfmlSoundSystem.hpp"
#include "../../Component/SfmlSound.hpp"
#include "../../Component/Audio.hpp"

SfmlSoundSystem::SfmlSoundSystem(std::shared_ptr<ComponentManager> &components) : AudioSystem(components)
{
    _usedComponents.push_back(typeid(SfmlSound).name());
    _usedComponents.push_back(typeid(Audio).name());
}

SfmlSoundSystem::~SfmlSoundSystem()
{
}

void SfmlSoundSystem::update()
{
    for (std::size_t i = 0; i < MAX_ENTITIES; i++)
    {
        if (!checkAvailableEntity(i))
            continue;
        Audio &audio = _componentManager->getComponent<Audio>(i).value();
        if (audio.status == NONE)
            continue;
        if (audio.status == PAUSE && audio.isPlayed)
            pause(i);
        if (audio.status == STOP && audio.isPlayed)
            stop(i);
        if (audio.status == PLAY)
            play(i);
    }
}

void SfmlSoundSystem::play(const std::size_t &entity)
{
    SfmlSound &sound = _componentManager->getComponent<SfmlSound>(entity).value();
    Audio &audio = _componentManager->getComponent<Audio>(entity).value();
    sound.sound.play();
    audio.isPlayed = true;
}

void SfmlSoundSystem::stop(const std::size_t &entity)
{
    SfmlSound &sound = _componentManager->getComponent<SfmlSound>(entity).value();
    Audio &audio = _componentManager->getComponent<Audio>(entity).value();
    sound.sound.stop();
    audio.isPlayed = false;
}

void SfmlSoundSystem::pause(const std::size_t &entity)
{
    SfmlSound &sound = _componentManager->getComponent<SfmlSound>(entity).value();
    Audio &audio = _componentManager->getComponent<Audio>(entity).value();
    sound.sound.pause();
    audio.isPlayed = false;
}