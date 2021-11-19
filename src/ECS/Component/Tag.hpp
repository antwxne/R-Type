/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Tag
*/

#ifndef TAG_HPP_
#define TAG_HPP_
#include <vector>

#ifdef __WIN32
enum TagType: int {
    BULLET,
    ENNEMY,
    PLAYER,
};

#else

enum TagType {
    BULLET,
    ENNEMY,
    PLAYER,
    POWERUP,
    SOUND
};
#endif

struct Tag {
    std::vector<TagType> type;
};
#endif /* !TAG_HPP_ */