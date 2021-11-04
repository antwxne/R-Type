/*
** EPITECH PROJECT, 2021
** B-CPP-500-PAR-5-1-babel-alan.sigal
** File description:
** main
*/

#include "AsioServer.hpp"

void printHelp(char *bin)
{
    std::cout << "USAGE" << std::endl << "\t" << bin << " port" << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl << std::endl << "\t port \t port of Babel server" << std::endl;
}

int main(int ac, char **av)
{
    int port = 0;

    if (ac == 2 && std::strcmp(av[1], "-h") == 0) {
        printHelp(av[0]);
        return 0;
    }
    if (ac != 2) {
        std::cout << av[0] << ": Bad usage" << std::endl;
        printHelp(av[0]);
        return 84;
    }
    port = std::atoi(av[1]);
    if (port <= 0) {
        std::cout << av[0] << ": Bad port" << std::endl;
        return 84;
    }
    try {
        AsioServer server(port);
        server.start();
        while (1)
        {
            server.update();
            sleep(0.01);
        }
    } catch (const std::system_error& e) {
        std::cout << av[0] << ": " << e.what() << std::endl;
        return 84;
    }
    return 0;
}