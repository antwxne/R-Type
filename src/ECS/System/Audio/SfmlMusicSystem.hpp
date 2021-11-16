/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlMusicSystem
*/

#ifndef SFMLMUSICSYSTEM_HPP_
#define SFMLMUSICSYSTEM_HPP_
#include "AudioSystem.hpp"

class SfmlMusicSystem : public AudioSystem {
    public:
        SfmlMusicSystem(std::shared_ptr<ComponentManager::ComponentsMap_t> &components);
        ~SfmlMusicSystem();
        void update() override;
        void play(int entity) override;
        void stop(int entity) override;
        void pause(int entity) override;
    protected:
    private:
};

#endif /* !SFMLMUSICSYSTEM_HPP_ */
