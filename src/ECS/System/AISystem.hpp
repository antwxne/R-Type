/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** AISystem
*/

#ifndef AISYSTEM_HPP_
#define AISYSTEM_HPP_

#include "ASystem.hpp"

class AISystem : public ASystem  {
    public:
        AISystem(std::shared_ptr<ComponentManager> &components);
        ~AISystem();
        void update() override;
    protected:
    private:
        void setDestination(const std::size_t &entity);
        void setPath(const std::size_t &entity);
        bool checkAvailableEntity(std::size_t entity) const override;
};

#endif /* !AISYSTEM_HPP_ */
