/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** sfmlSound
*/

#ifndef SFMLSOUND_HPP_
#define SFMLSOUND_HPP_
#include "SFML/Audio.hpp"
#include "Graphical/SfmlSoundHandler.hpp"

struct SfmlSound
{
    bool play;
    SoundType soundtype;
    std::shared_ptr<sf::Sound> sound;
};

#endif /* !SFMLSOUND_HPP_ */
