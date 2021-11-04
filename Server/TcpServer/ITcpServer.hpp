/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** ITcpServer
*/

#ifndef ITCPSERVER_HPP_
#define ITCPSERVER_HPP_

class ITcpServer {
    public:
        virtual ~ITcpServer() = default;
        virtual void start() = 0;
        virtual void stop() = 0;
        virtual void run() = 0;
        virtual void update() = 0;
        virtual void acceptClientsConnection() = 0;

    protected:
    private:
};

#endif /* !ITCPSERVER_HPP_ */
