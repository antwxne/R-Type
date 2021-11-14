/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** main
*/

#include "src/Graphical/SfmlDisplay.hpp"
#include "src/Graphical/SfmlParallax.hpp"
#include "src/ECS/ECS.hpp"
#include "src/ECS/component.hpp"
#include "src/ECS/system.hpp"
#include "src/R-Type/Rtype.hpp"

int main()
{
    Rtype rtype;

    rtype.start();
    return (0);
}

/*
Check les colisions entre toute les entité qui update les componants
*/