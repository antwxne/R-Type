/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** MoveSystem
*/

#ifndef MOVESYSTEM_HPP_
#define MOVESYSTEM_HPP_

#include "ASystem.hpp"
#include <vector>

class MoveSystem : public ASystem {
public:
    MoveSystem(std::shared_ptr<ComponentManager> components);
    ~MoveSystem();
    void update() override;

protected:
private:
    bool checkAvailableEntity(const size_t entity) const override;

};

#endif /* !MOVESYSTEM_HPP_ */
