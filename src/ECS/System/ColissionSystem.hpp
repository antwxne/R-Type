/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** ColissionSystem
*/

#ifndef COLISSIONSYSTEM_HPP_
#define COLISSIONSYSTEM_HPP_
#include "ASystem.hpp"

class ColissionSystem : public ASystem {
    public:
        ColissionSystem();
        ~ColissionSystem();
        void update() override;
    protected:
    private:
};

#endif /* !COLISSIONSYSTEM_HPP_ */