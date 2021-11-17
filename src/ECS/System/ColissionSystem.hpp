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
    ColissionSystem(std::shared_ptr<ComponentManager> &components);
    ~ColissionSystem();
    void update() override;
protected:
private:
    bool checkAvailableEntity(std::size_t entity) const override;
};

#endif /* !COLISSIONSYSTEM_HPP_ */