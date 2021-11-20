/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** UdpGameClient
*/

#ifndef UDPGAMECLIENT_HPP_
#define UDPGAMECLIENT_HPP_

#include <list>

#include "UdpClient.hpp"
#include "Graphical/SfmlEventFactory.hpp"
#include "UdpGameClientMessageHandler.hpp"
#include "NetworkEntityInformation.hpp"

class UdpGameClient : public UdpClient {
    public:
        UdpGameClient(const std::string &ip, int port);
        ~UdpGameClient();
        void start() override;
        void run() override;
        void sendRegisterMessage();
        void sendCommand(ControlGame control);
        void addEntityInfo(const NetworkEntityInformation& info);
        std::list<NetworkEntityInformation> &getEntitiesInfos();
        void resetEntitiesList();
        void sendCommands(const std::list<ControlGame> &controls);

    protected:
    private:
        UdpGameClientMessageHandler _gameHandler;
        std::list<NetworkEntityInformation> _entitiesInfos;
        std::mutex _entitiesInfosMutex;
};

#endif /* !UDPGAMECLIENT_HPP_ */
