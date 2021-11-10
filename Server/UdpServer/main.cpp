/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** main
*/

#include "GameUdpServer.hpp"

int main(void)
{
    GameUdpServer server(2);

    server.start();
}