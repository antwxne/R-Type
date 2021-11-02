/*
** EPITECH PROJECT, 2021
** Boostrap
** File description:
** Entity
*/

#include <cstddef>
#include <iostream>

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

class Entity {
    public:
        Entity(size_t size);
        ~Entity();
        void operator>>(size_t &object) const;
        bool operator<(size_t size);


    protected:
    private:
        std::size_t _size;
};

std::ostream& operator<<(std::ostream& os, const Entity& entity)
{
    size_t id;
    entity >> id;
    os << id;
    return os;
}



#endif /* !ENTITY_HPP_ */
