/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** AudioSystem
*/

#ifndef AUDIOSYSTEM_HPP_
#define AUDIOSYSTEM_HPP_

#include "ECS/System/ASystem.hpp"

class AudioSystem : public ASystem {
    public:
        AudioSystem(const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManager);
        ~AudioSystem();
        virtual void update() = 0;
        virtual void play(const std::size_t &entity) = 0;
        virtual void stop(const std::size_t &entity) = 0;
        virtual void pause(const std::size_t &entity) = 0;
    protected:
    private:
};

#endif /* !AUDIOSYSTEM_HPP_ */
