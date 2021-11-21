/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** ExploseClock
*/

#ifndef EXPLOSECLOCK_HPP_
#define EXPLOSECLOCK_HPP_

#include <chrono>

struct ExploseClock
{
    float elapsed;
    std::chrono::system_clock::time_point clock;
};

#endif /* !EXPLOSECLOCK_HPP_ */
