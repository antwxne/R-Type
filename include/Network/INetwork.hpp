/*
** EPITECH PROJECT, 2021
** 
** File description:
** INetwork
*/

#ifndef INETWORK_HPP_
#define INETWORK_HPP_

#include "Message.hpp"
#include "network.hpp"

class INetwork {
    public:
        virtual ~INetwork() = default;
        virtual void sendMessage(Message<MessageType> &message) = 0;
        virtual void readMessageHeader() = 0;
        virtual void readMessageBody() = 0;
        virtual void writeMessageHeader(Message<MessageType> &message) = 0;
        virtual void writeMessageBody(Message<MessageType> &message) = 0;
    protected:
    private:
};

#endif /* !INETWORK_HPP_ */
