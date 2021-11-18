/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** sfmlSound
*/

#ifndef SFMLSOUND_HPP_
#define SFMLSOUND_HPP_
#include "SFML/Audio.hpp"

struct SfmlSound
{
    bool play;
    sf::Sound sound;
    std::shared_ptr<sf::SoundBuffer> soundBuffer;
};

#endif /* !SFMLSOUND_HPP_ */
