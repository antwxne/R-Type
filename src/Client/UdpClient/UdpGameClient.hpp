/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** UdpGameClient
*/

#ifndef UDPGAMECLIENT_HPP_
#define UDPGAMECLIENT_HPP_

#include "UdpClient.hpp"
#include "Graphical/SfmlEventFactory.hpp"

class UdpGameClient : public UdpClient {
    public:
        UdpGameClient(const std::string &ip, int port);
        ~UdpGameClient();
        void start() override;
        void sendRegisterMessage();
        void sendCommand(ControlGame control);

    protected:
    private:
};

#endif /* !UDPGAMECLIENT_HPP_ */
