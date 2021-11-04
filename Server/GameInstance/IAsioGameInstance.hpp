/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** IAsioGameInstance
*/

#ifndef IASIOGAMEINSTANCE_HPP_
#define IASIOGAMEINSTANCE_HPP_

#include "IGameInstance.hpp"
#include <memory>
#include "../ClientInstance.hpp"

class IAsioGameInstance : public IGameInstance {
    public:
        virtual ~IAsioGameInstance() = default;
        virtual void setHost(std::shared_ptr<ClientInstance> host) = 0;
        virtual bool addClient(std::shared_ptr<ClientInstance> client) = 0;
    protected:
    private:
};

#endif /* !IASIOGAMEINSTANCE_HPP_ */
