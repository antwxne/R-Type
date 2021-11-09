/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#ifndef RTYPE_SYSTEMMANAGER_HPP
#define RTYPE_SYSTEMMANAGER_HPP

#include <memory>
#include <unordered_map>

#include "ASystem.hpp"
#include "Component/IComponent.hpp"
#include "SparseArray/SparseArray.hpp"

class SystemManager {
public:
    using ComponentsMap_t = std::unordered_map<std::type_info, std::shared_ptr<SparseArray<IComponent>>>;
    using SystemsMap_t = std::unordered_map<std::type_info, std::shared_ptr<ASystem>>;
    template<typename T>
    std::shared_ptr<T> registerSystem(std::shared_ptr<ComponentsMap_t> &components)
    {
        _systemsMap.emplace(typeid(T), std::make_shared<T>(components));
    }

    template<typename T>
    void setSignature(const Signature &signature)
    {
        _systemsMap[typeid(T)]->setSignature(signature);
    }
    template<typename T>
    const Signature &getSignature() const
    {
        return _systemsMap.at(typeid(T))->getSignature();
    }

private:
    SystemsMap_t _systemsMap;
};

#endif //RTYPE_SYSTEMMANAGER_HPP
