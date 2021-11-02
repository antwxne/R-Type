/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#ifndef SPARSE_HPP_
#define SPARSE_HPP_

#include <vector>

template <typename Component> // You can also mirror the definition of std :: vector , that takes an additional allocator.

class sparse_array {
public:
    using value_type = Component; // optional component type
    using reference_type = value_type &;
    using const_reference_type = value_type const &;
    using container_t = std::vector<value_type>; // optionally add your allocator template here.
    using size_type = typename container_t::size_type;
    using iterator = typename container_t::iterator;
    using const_iterator = typename container_t::const_iterator;

public:
    sparse_array();                         // You can add more constructors .
    sparse_array(sparse_array const &other)     // copy constructor
    {
        _data.assign(other);
    }
    sparse_array(sparse_array &&other) noexcept // move constructor
    {
        _data.assign(other);
    }
    ~sparse_array();
    sparse_array &operator=(sparse_array const &other) // copy assignment operator
    {
        _data = other;
    }
    sparse_array &operator=(sparse_array &&other) noexcept // move assignment operator
    {
        _data = other;
    }
    reference_type operator[](size_t idx)
    {
        return _data[idx];
    }
    const_reference_type operator[](size_t idx) const
    {
        return _data[idx];
    }
    iterator begin()
    {
        return _data.begin();
    }
    const_iterator begin() const
    {
        return _data.begin();
    }
    const_iterator cbegin() const
    {
        return _data.cbegin();
    }
    iterator end()
    {
        return _data.end();
    }
    const_iterator end() const
    {
        return _data.end();
    }
    const_iterator cend() const
    {
        return _data.cend();
    }
    size_type size() const
    {
        return _data.size();
    }
    reference_type insert_at(size_type pos, Component const &obj)
    {
        auto it = _data.begin();
        if (pos > _data.size()) {
            _data.resize(pos);
        }
        for (size_type i = 0; i < pos; ++i) {
            ++it;
        }
        return _data.insert(it, obj);
    }
    reference_type insert_at(size_type pos, Component &&);
    template <class... Params>
    reference_type emplace_at(size_type pos, Params &&...); // optional
    void erase(size_type pos);
    size_type get_index(value_type const &) const;

private:
    container_t _data;
};

#endif /* !SPARSE_HPP_ */
