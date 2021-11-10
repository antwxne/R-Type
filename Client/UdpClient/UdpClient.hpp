/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** UdpClient
*/

#ifndef UDPCLIENT_HPP_
#define UDPCLIENT_HPP_


#include <asio.hpp>

class UdpClient {
    public:
        UdpClient(int port);
        ~UdpClient();
        void start();

    protected:
    private:
    asio::io_context _ioContext;
    asio::ip::udp::socket _socket;
    asio::ip::udp::endpoint _serverEndpoint;
};

#endif /* !UDPCLIENT_HPP_ */
