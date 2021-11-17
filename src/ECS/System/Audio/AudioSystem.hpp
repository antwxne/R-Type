/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** AudioSystem
*/

#ifndef AUDIOSYSTEM_HPP_
#define AUDIOSYSTEM_HPP_

#include "../ASystem.hpp"

class AudioSystem : public ASystem {
    public:
        AudioSystem(std::shared_ptr<ComponentManager> &components);
        ~AudioSystem();
        virtual void update() = 0;
        virtual void play(const std::size_t &entity) = 0;
        virtual void stop(const std::size_t &entity) = 0;
        virtual void pause(const std::size_t &entity) = 0;
    protected:
    private:
};

#endif /* !AUDIOSYSTEM_HPP_ */