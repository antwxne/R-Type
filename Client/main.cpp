/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** main
*/

#include "TcpClient/TcpClient.hpp"

int main(int ac, char **av)
{
    TcpClient client;

    client.tryConnect("127.0.0.1", 8080);
    
    while (client.isConnected() == false)
    {
        std::cout << "wait\n";
        sleep(0.1);
    }

    if (strlen(av[1]) == 1)
    {
        client.createGame("testomg");
        sleep(1);
        client.leaveGame("testomg");
    }
    else
    {
        client.joinGame("testomg");
        sleep(1);
        client.leaveGame("testomg");
    }
    client.start();
}