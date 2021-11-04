/*
** EPITECH PROJECT, 2021
** B-CPP-500-PAR-5-1-babel-alan.sigal
** File description:
** ClientInstanceMessage
*/

#ifndef CLIENTINSTANCEMESSAGE_HPP_
#define CLIENTINSTANCEMESSAGE_HPP_

#include "../Network/Message.hpp"
#include <memory>
//#include "ClientInstance.hpp"

class ClientInstance;

template<typename T>
class ClientInstanceMessage {
    public:
        ClientInstanceMessage(Message<T> &message, std::shared_ptr<ClientInstance> client)
        : message(message), client(client)
        {

        };
        ~ClientInstanceMessage()
        {

        }
    public:
        Message<T> message;
        std::shared_ptr<ClientInstance> client;
};

#endif /* !CLIENTINSTANCEMESSAGE_HPP_ */
