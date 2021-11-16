/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

enum statusTypeAudio {
    PLAY,
    STOP,
    PAUSE,
    ISPLAYED,
    NONE,
};

struct Audio
{
    std::size_t idAudio;
    statusTypeAudio status;
    bool isPlayed;
};

#endif /* !SOUND_HPP_ */
