/*
** EPITECH PROJECT, 2021
** B-CPP-500-PAR-5-1-babel-alan.sigal
** File description:
** main
*/

#include "TcpServer/TcpAsioServer.hpp"

void printHelp(char *bin)
{
    std::cout << "USAGE" << std::endl << "\t" << bin << " port" << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl << std::endl << "\t port \t port of Babel server" << std::endl;
}

int checkArgs(int ac, char **av)
{
    if (ac == 2 && std::strcmp(av[1], "-h") == 0) {
        printHelp(av[0]);
        return 1;
    }
    if (ac != 2) {
        std::cout << av[0] << ": Bad usage" << std::endl;
        printHelp(av[0]);
        return -1;
    }
    return 0;
}

int getPort(char **av)
{
    int port = std::atoi(av[1]);
    if (port <= 0) {
        std::cout << av[0] << ": Bad port" << std::endl;
        return -1;
    }
    return port;
}

int launchServer(int port)
{
    try {
        TcpAsioServer server(port);
        server.start();
    } catch (const std::system_error& e) {
        std::cout << e.what() << std::endl;
        return 84;
    }
    return 0;
}

int main(int ac, char **av)
{
    int port = 0;
    int argCheck = checkArgs(ac, av);

    if (argCheck == 1)
        return 0;
    else if (argCheck == -1)
        return 84;

    port = getPort(av);
    if (port > 0)
        return launchServer(port);
}

//#include "ECS/ECS.hpp"
//#include "ECS/component.hpp"
//#include "ECS/system.hpp"
//
//int main()
//{
//    ECS ecs;
//
//    ecs.registerComponent<Position>();
//    ecs.registerComponent<Texture>();
//    ecs.registerComponent<Scale>();
//    ecs.registerComponent<Rotate>();
//    ecs.registerComponent<Color>();
//    ecs.registerComponent<SfmlSprite>();
//
//    auto draw = ecs.registerSystem<SfmlDrawSystem>();
//    Entity player = ecs.createEntity();
//    ecs.subToComponent(player, Position{50, 50});
//    ecs.subToComponent(player, Texture{TextureType::Player});
//    ecs.subToComponent(player, Scale{1});
//    ecs.subToComponent(player, Color{ColorType::None});
//    ecs.subToComponent(player, SfmlSprite{sf::Sprite()});
//}