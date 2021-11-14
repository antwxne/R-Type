/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlMenu
*/

#ifndef SFMLMENU_HPP_
#define SFMLMENU_HPP_

#include <list>
#include "SfmlDisplay.hpp"
#include "SfmlButton.hpp"

class SfmlMenu {
    public:
        SfmlMenu();
        ~SfmlMenu();

    protected:
    private:
        std::list<SfmlButton> _buttonList;

};

#endif /* !SFMLMENU_HPP_ */
