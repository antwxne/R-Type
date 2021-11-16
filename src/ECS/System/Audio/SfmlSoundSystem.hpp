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
        SfmlSoundSystem(std::shared_ptr<ComponentManager::ComponentsMap_t> &components);
        ~SfmlSoundSystem();
        virtual void update() = 0;
        virtual void play(int entity) = 0;
        virtual void stop(int entity) = 0;
        virtual void pause(int entity) = 0;
    protected:
    private:
};

#endif /* !SFMLSOUNDSYSTEM_HPP_ */
