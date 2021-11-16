/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlMusicSystem
*/

#include "SfmlMusicSystem.hpp"
#include "../../Component/SfmlMusic.hpp"
#include "../../Component/Audio.hpp"

SfmlMusicSystem::SfmlMusicSystem(std::shared_ptr<ComponentManager::ComponentsMap_t> &components) : AudioSystem(components)
{
    _usedComponents.push_back(typeid(SfmlMusic));
    _usedComponents.push_back(typeid(Audio));
}

SfmlMusicSystem::~SfmlMusicSystem()
{
}

void SfmlMusicSystem::update()
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

void SfmlMusicSystem::play(int entity)
{
    SfmlMusic &music = std::any_cast<SfmlMusic &>(_components->at(typeid(SfmlMusic))->getData(entity).value());
    Audio &audio = std::any_cast<Audio &>(_components->at(typeid(Audio))->getData(entity).value());
    music.music.play();
    audio.isPlayed = true;
}

void SfmlMusicSystem::stop(int entity)
{
    SfmlMusic &music = std::any_cast<SfmlMusic &>(_components->at(typeid(SfmlMusic))->getData(entity).value());
    Audio &audio = std::any_cast<Audio &>(_components->at(typeid(Audio))->getData(entity).value());
    music.music.stop();
    audio.isPlayed = false;
}

void SfmlMusicSystem::pause(int entity)
{
    SfmlMusic &music = std::any_cast<SfmlMusic &>(_components->at(typeid(SfmlMusic))->getData(entity).value());
    Audio &audio = std::any_cast<Audio &>(_components->at(typeid(Audio))->getData(entity).value());
    music.music.pause();
    audio.isPlayed = false;
}