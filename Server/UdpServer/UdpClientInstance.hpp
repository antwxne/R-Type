/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** UdpClientInstance
*/

#ifndef UDPCLIENTINSTANCE_HPP_
#define UDPCLIENTINSTANCE_HPP_

#include <asio.hpp>

class UdpClientInstance {
    public:
        UdpClientInstance(asio::io_context& asioContext, asio::ip::udp::socket socket);
        ~UdpClientInstance();

    protected:
    private:
        asio::io_context& _asioContext;
        asio::ip::udp::socket _socket;
};

#endif /* !UDPCLIENTINSTANCE_HPP_ */
