/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#ifndef RTYPE_SOUNDENTITY_HPP
#define RTYPE_SOUNDENTITY_HPP

#include <string>

#include "IEntityRegister.hpp"

class SoundEntity: public IEntityRegister {
public:
    SoundEntity(const std::string& soundPath);
    ~SoundEntity() = default;

    void create(
        const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManager) override;

private:
    std::string _soundPath;
};

#endif //RTYPE_SOUNDENTITY_HPP
