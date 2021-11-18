/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlSoundSystem
*/

#ifndef SFMLSOUNDSYSTEM_HPP_
#define SFMLSOUNDSYSTEM_HPP_

#include "AudioSystem.hpp"

class SfmlSoundSystem : public AudioSystem {
public:
    SfmlSoundSystem(const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManagers);
    ~SfmlSoundSystem();
    void update() override;
    void play(const std::size_t &entity) override;
    void stop(const std::size_t &entity) override;
    void pause(const std::size_t &entity) override;
protected:
private:
    bool checkAvailableEntity(const size_t entity) const override;

};

#endif /* !SFMLSOUNDSYSTEM_HPP_ */
