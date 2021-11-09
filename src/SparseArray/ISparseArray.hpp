/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** ISparseArray
*/

#ifndef ISPARSEARRAY_HPP_
#define ISPARSEARRAY_HPP_

#include "Entity/Entity.hpp"

class ISparseArray {
    public:
        virtual ~ISparseArray() = default;
        virtual void entityDestroyed(const Entity &entity) = 0;
    protected:
    private:
};

#endif /* !ISPARSEARRAY_HPP_ */
