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
#include "ECS/Component/ComponentException.hpp"
#include "ECS/Entity/EntityException.hpp"

template<typename T>
class SparseArray {
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
        std::cout << "DELETE IN SPARSE ARRAY" << std::endl;
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

    std::optional<T> &getData(const Entity &entity) noexcept
    {
        std::size_t index;

        entity >> index;
        return _dataVector[index];
    }

    std::optional<T> &operator[](const size_t index) noexcept
    {
        return _dataVector[index];
    }
    std::optional<T> &operator[](const Entity &entity) noexcept
    {
        std::size_t index;

        entity >> index;
        return _dataVector[index];
    }
    const std::optional<T> &operator[](const size_t index) const noexcept
    {
        return _dataVector[index];
    }
    std::optional<T> &getData(const size_t &index) noexcept
    {
        return _dataVector[index];
    }
    void entityDestroyed(const Entity &entity)
    {
        deleteData(entity);
    }
protected:
private:
    std::vector<std::optional<T>> _dataVector;
};

#endif /* !SPARSEARRAY_HPP_ */
