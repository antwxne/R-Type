/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** UdpAsioServer
*/

#ifndef UDPASIOSERVER_HPP_
#define UDPASIOSERVER_HPP_

#include <thread>
#include <asio.hpp>

class UdpAsioServer {
    public:
        UdpAsioServer();
        ~UdpAsioServer();
    protected:
    private:
        asio::io_context _asioContext;
		std::thread _threadContext;
    
};

#endif /* !UDPASIOSERVER_HPP_ */
