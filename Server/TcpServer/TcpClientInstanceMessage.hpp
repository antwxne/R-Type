/*
** EPITECH PROJECT, 2021
** B-CPP-500-PAR-5-1-babel-alan.sigal
** File description:
** TcpClientInstanceMessage
*/

#ifndef TcpClientInstanceMESSAGE_HPP_
#define TcpClientInstanceMESSAGE_HPP_

#include "Message.hpp"
#include <memory>
#include "TcpClientInstance.hpp"

class TcpClientInstance;

template<typename T>
class TcpClientInstanceMessage {
    public:
        TcpClientInstanceMessage(Message<T> &message, std::shared_ptr<TcpClientInstance> client)
        : message(message), client(client)
        {

        };
        ~TcpClientInstanceMessage()
        {

        }
    public:
        Message<T> message;
        std::shared_ptr<TcpClientInstance> client;
};

#endif /* !TcpClientInstanceMESSAGE_HPP_ */
