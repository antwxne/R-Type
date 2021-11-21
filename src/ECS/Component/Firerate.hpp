/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Firerate
*/

#ifndef FIRERATE_HPP_
#define FIRERATE_HPP_

#include <chrono>

typedef std::chrono::high_resolution_clock Clock;



struct Firerate
{
    float delay;
    std::chrono::system_clock::time_point clock;
};


#endif /* !FIRERATE_HPP_ */