/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlSoundSystem
*/

#ifndef SFMLSOUNDSYSTEM_HPP_
#define SFMLSOUNDSYSTEM_HPP_

#include "../ASystem.hpp"
#include "Graphical/SfmlSoundHandler.hpp"

class SfmlSoundSystem : public ASystem
{
public:
    SfmlSoundSystem(const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManagers);
    ~SfmlSoundSystem();
    void update() override;
protected:
private:
    bool checkAvailableEntity(const std::size_t entity) const override;
    SfmlSoundHandler _handler;

};

#endif /* !SFMLSOUNDSYSTEM_HPP_ */
