/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** ClientInformations
*/

#include "ClientInformations.hpp"

ClientInformations::ClientInformations()
{
}

ClientInformations::~ClientInformations()
{
}


void ClientInformations::setName(const std::string &name)
{
    _name = name;
}

std::string ClientInformations::getName()
{
    return _name;
}