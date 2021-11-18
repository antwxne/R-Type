/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#ifndef RTYPE_PLAYSOUNDEVENTS_HPP
#define RTYPE_PLAYSOUNDEVENTS_HPP

#include "ECS/System/ASystem.hpp"

class PlaySoundEvents: ASystem {
public:
    PlaySoundEvents(const std::shared_ptr<ComponentManager> &components, const std::shared_ptr<EntityManager> &entityManager);

    void update() override;
private:
    bool checkAvailableEntity(std::size_t entity) const override;
};

#endif //RTYPE_PLAYSOUNDEVENTS_HPP
