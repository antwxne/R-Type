/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** IASystem
*/

#ifndef IASYSTEM_HPP_
#define IASYSTEM_HPP_

#include "ASystem.hpp"

class IASystem : public ASystem  {
    public:
        IASystem(std::shared_ptr<ComponentManager> &components);
        ~IASystem();
        void update() override;
    protected:
    private:
};

#endif /* !IASYSTEM_HPP_ */
