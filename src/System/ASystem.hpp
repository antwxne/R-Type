/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#ifndef RTYPE_ASYSTEM_HPP
#define RTYPE_ASYSTEM_HPP

#include <memory>

#include "SparseArray/SparseArray.hpp"
#include "Component/IComponent.hpp"

class ASystem {
    using ComponentsMap_t = std::unordered_map<std::type_info, std::shared_ptr<SparseArray<IComponent>>>;
public:
    ASystem(std::shared_ptr<ComponentsMap_t> &components);

    const Signature &getSignature() const;
    void setSignature(const Signature &signature);
    virtual void update() = 0;
private:
    std::shared_ptr<ComponentsMap_t> _components;
    Signature _signature;
};

#endif //RTYPE_ASYSTEM_HPP
