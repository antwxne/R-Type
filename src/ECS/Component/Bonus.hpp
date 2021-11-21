/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Bonus
*/

#ifndef BONUS_HPP_
#define BONUS_HPP_

enum BonusType
{
    ShootSpeedBonus = 0,
    HealBonus = 1,
};

struct Bonus
{
    BonusType type;
};

#endif /* !BONUS_HPP_ */
