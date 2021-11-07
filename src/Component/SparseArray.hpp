/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SparseArray
*/

#ifndef SPARSEARRAY_HPP_
#define SPARSEARRAY_HPP_

#include <array>
#include <functional>
#include <optional>

#include "rtype.h"
#include "ISparseArray.hpp"
#include "ComponentException.hpp"
#include "Entity/EntityException.hpp"

template<typename T>
class SparseArray : public ISparseArray {
public:
    SparseArray() = default;
    ~SparseArray() = default;

    void insertData(const Entity &entity, const T &component)
    {
        std::size_t index;

        entity >> index;
        if (_componentArray[index].has_value()) {
            throw ComponentException(entity, component,
                "can't insert component.");
        }
        _componentArray[index] = component;
    }

    void deleteData(const Entity &entity)
    {
        std::size_t index;

        entity >> index;
        if (!_componentArray[index].has_value()) {
            throw ComponentException(entity, _componentArray[index],
                "can't delete component, component doesn't exist.");
        }
        _componentArray[index] = std::nullopt;
    }

    const T &getData(const Entity &entity) const
    {
        std::size_t index;

        entity >> index;
        if (!_componentArray[index].has_value()) {
            throw ComponentException(entity, _componentArray[index],
                "can't get component, component doesn't exist.");
        }
        return _componentArray[index];
    }

    T &getData(const Entity &entity)
    {
        std::size_t index;

        entity >> index;
        if (!_componentArray[index].has_value()) {
            throw ComponentException(entity, _componentArray[index],
                "can't get component, component doesn't exist.");
        }
        return _componentArray[index];
    }

    void entityDestroyed(const Entity &entity) override
    {
        deleteData(entity);
    }

protected:
private:
    std::array<std::optional<T>, MAX_ENTITIES> _componentArray;
};

#endif /* !SPARSEARRAY_HPP_ */
