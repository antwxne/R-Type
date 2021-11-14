/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** GameUdpMessage
*/

#ifndef GAMEUDPMESSAGE_HPP_
#define GAMEUDPMESSAGE_HPP_

#include "Message.hpp"

template<typename T>
class GameUdpMessage {
    public:
        GameUdpMessage(Message<T> &message, int nPlayer) : message(message), nPlayer(nPlayer)
        {

        }
        ~GameUdpMessage()
        {

        }
    public:
        Message<T> message;
        int nPlayer;
};

#endif /* !GAMEUDPMESSAGE_HPP_ */
