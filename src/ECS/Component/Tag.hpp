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
    ENEMY,
    PLAYER,
    SOUND,
    EXPLOSION,

};

#else

enum TagType {
    BULLET,
    ENEMY,
    PLAYER,
    POWERUP,
    SOUND,
    EXPLOSION,
};
#endif

struct Tag {
    std::vector<TagType> type;
};
#endif /* !TAG_HPP_ */