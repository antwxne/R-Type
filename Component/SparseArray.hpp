/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SparseArray
*/

#ifndef SPARSEARRAY_HPP_
#define SPARSEARRAY_HPP_

#include "ISparseArray.hpp"
#include <map>

template<typename T>
class SparseArray : public ISparseArray {
    public:
        SparseArray() {};
        ~SparseArray() {};
        void insertData(Entity entity, T component)
        {
            if (_componentMap.find(entity) != _componentMap.end())
            {
                std::cout << "Entity " << entity << " already in array for insertData" << std::endl;
                return;
            }
            _componentMap[entity] = component;
        }

        void deleteData(Entity entity)
        {
            if (_componentMap[entity] == _componentMap.end())
            {
                std::cout << "Entity " << entity << " not found for deleteData" << std::endl;
                return;
            }
            _componentMap.erase(_componentMap.find(entity));
        }
        
        T& getData(Entity entity)
        {
            if (_componentMap[entity] == _componentMap.end())
            {
                std::cout << "Entity " << entity << " not found for getData" << std::endl;
                return NULL;
            }
            return _componentMap[entity];
        }

        void entityDestroyed(Entity entity) override
        {
            deleteData(entity);
        }

    protected:
    private:
        std::map<Entity, T, EntityCompare> _componentMap;
};

#endif /* !SPARSEARRAY_HPP_ */
