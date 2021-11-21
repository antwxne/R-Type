/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** EnemyEntity
*/

#ifndef ENEMYENTITY_HPP_
#define ENEMYENTITY_HPP_

#include "../component.hpp"
#include "../Component/ComponentManager.hpp"
#include "EntityManager.hpp"
#include "IEntityRegister.hpp"
#include "../../DLLloader/DLLloader.hpp"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <ctime>
#include <cstdlib>

class EnemyEntity : public IEntityRegister {
public:
    EnemyEntity(const std::string &filename);
    ~EnemyEntity();

    void create(const std::shared_ptr<ComponentManager> &componentManager,
        const std::shared_ptr<EntityManager> &entityManager
    );
    void setPostion(const Position &pos);
protected:
private:
    void getLibraries();
    void loadEnemyLib(std::string &filename);

    Position _pos;
    sf::IntRect _textureRect;

    std::string _path;
    std::vector<std::string> _enemyList;
    std::shared_ptr<DLLloader<IEntityRegister>> _enemyLoaded;

    std::chrono::_V2::system_clock::time_point _clock;
    float _elapsed;
};

#endif /* !ENEMYENTITY_HPP_ */
