/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** ClientInformations
*/

#ifndef CLIENTINFORMATIONS_HPP_
#define CLIENTINFORMATIONS_HPP_

#include <string>

class ClientInformations {
    public:
        ClientInformations();
        ~ClientInformations();
        void setName(const std::string &name);
        std::string getName();
    private:
        std::string _name = "";
};

#endif /* !CLIENTINFORMATIONS_HPP_ */
