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
        bool operator==(const Entity &entity) const;
    protected:
    private:
        std::size_t _size;
};

std::ostream& operator<<(std::ostream& os, const Entity& entity);

class EntityCompare
{
    public:
        size_t operator() (const Entity&e1) const
        {
            size_t id1;

            e1 >> id1;

            return id1;
        }
};



#endif /* !ENTITY_HPP_ */
