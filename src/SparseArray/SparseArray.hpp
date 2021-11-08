/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SparseArray
*/

#ifndef SPARSEARRAY_HPP_
#define SPARSEARRAY_HPP_

#include <vector>
#include <functional>
#include <optional>

#include "rtype.h"
#include "ISparseArray.hpp"
#include "Component/ComponentException.hpp"
#include "Entity/EntityException.hpp"

template<typename T>
class SparseArray : public ISparseArray {
public:
    using iterator = typename std::vector<T>::iterator;
    SparseArray(std::size_t size)
    {
        _dataVector.resize(size);
        _dataVector.assign(size, std::nullopt);
    }
    ~SparseArray() = default;

    void insertData(const Entity &entity, const T &component)
    {
        std::size_t index;

        entity >> index;
        if (_dataVector[index].has_value()) {
            throw ComponentException(entity, component,
                "can't insert component.");
        }
        _dataVector[index] = component;
    }

    void deleteData(const Entity &entity)
    {
        std::size_t index;

        entity >> index;
        if (!_dataVector[index].has_value()) {
            throw ComponentException(entity, _dataVector[index],
                "can't delete component, component doesn't exist.");
        }
        _dataVector[index] = std::nullopt;
    }

    const T &getData(const Entity &entity) const
    {
        std::size_t index;

        entity >> index;
        if (!_dataVector[index].has_value()) {
            throw ComponentException(entity, _dataVector[index],
                "can't get component, component doesn't exist.");
        }
        return _dataVector[index];
    }

    T &getData(const Entity &entity)
    {
        std::size_t index;

        entity >> index;
        if (!_dataVector[index].has_value()) {
            throw ComponentException(entity, _dataVector[index],
                "can't get component, component doesn't exist.");
        }
        return _dataVector[index];
    }

    void entityDestroyed(const Entity &entity) override
    {
        deleteData(entity);
    }

protected:
private:
    std::vector<std::optional<T>> _dataVector;
};

#endif /* !SPARSEARRAY_HPP_ */
