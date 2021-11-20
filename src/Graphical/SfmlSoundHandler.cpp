/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlSoundHandler
*/

#include "SfmlSoundHandler.hpp"


SfmlSoundHandler::SfmlSoundHandler()
{
    addMap(SoundType::Shot, "assets/sound/shot.wav");
    addMap(SoundType::Explosion, "assets/sound/explosion.wav");
}

SfmlSoundHandler::~SfmlSoundHandler()
{
}

void SfmlSoundHandler::addMap(SoundType type, const std::string &path)
{
    std::shared_ptr<sf::SoundBuffer> buffer = std::make_shared<sf::SoundBuffer>();
    buffer->loadFromFile(path);
    _map[type] = buffer;
}

std::shared_ptr<sf::SoundBuffer> SfmlSoundHandler::getSoundBuffer(SoundType type)
{
    if (_map.find(type) == _map.end())
        return nullptr;
    return _map[type];
}