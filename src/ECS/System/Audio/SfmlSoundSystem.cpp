/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlSound
*/

#include "SfmlSoundSystem.hpp"
#include "../../Component/SfmlSound.hpp"
#include "../../Component/Audio.hpp"

SfmlSoundSystem::SfmlSoundSystem(std::shared_ptr<ComponentManager::ComponentsMap_t> &components) : AudioSystem(components)
{
    _usedComponents.push_back(typeid(SfmlSound));
    _usedComponents.push_back(typeid(Audio));
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
        Audio &audio = std::any_cast<Audio &>(_components->at(typeid(Audio))->getData(i).value());
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

void SfmlSoundSystem::play(int entity)
{
    SfmlSound &sound = std::any_cast<SfmlSound &>(_components->at(typeid(SfmlSound))->getData(entity).value());
    Audio &audio = std::any_cast<Audio &>(_components->at(typeid(Audio))->getData(entity).value());
    sound.sound.play();
    audio.isPlayed = true;
}

void SfmlSoundSystem::stop(int entity)
{
    SfmlSound &sound = std::any_cast<SfmlSound &>(_components->at(typeid(SfmlSound))->getData(entity).value());
    Audio &audio = std::any_cast<Audio &>(_components->at(typeid(Audio))->getData(entity).value());
    sound.sound.stop();
    audio.isPlayed = false;
}

void SfmlSoundSystem::pause(int entity)
{
    SfmlSound &sound = std::any_cast<SfmlSound &>(_components->at(typeid(SfmlSound))->getData(entity).value());
    Audio &audio = std::any_cast<Audio &>(_components->at(typeid(Audio))->getData(entity).value());
    sound.sound.pause();
    audio.isPlayed = false;
}