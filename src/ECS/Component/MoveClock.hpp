/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** MoveClock
*/

#ifndef MOVECLOCK_HPP_
#define MOVECLOCK_HPP_

#include <chrono>

struct MoveClock
{
    float elapsed;
    std::chrono::_V2::system_clock::time_point clock;
};

#endif /* !MOVECLOCK_HPP_ */
