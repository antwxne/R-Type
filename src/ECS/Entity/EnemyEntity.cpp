/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** EnemyEntity
*/

#include "EnemyEntity.hpp"

typedef std::chrono::high_resolution_clock Clock;

EnemyEntity::EnemyEntity(const std::string &path): IEntityRegister()
{
    _pos = {1920, 0};
    _enemyLoaded = NULL;
    _path = path;
    _elapsed = 10000;
    _clock = Clock::now();
    this->getLibraries();
}

EnemyEntity::~EnemyEntity()
{
}

void EnemyEntity::create(
    const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManager)
{
    auto delay = std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - _clock).count();
    if (delay >= _elapsed) {
        _enemyList.clear();
        this->getLibraries();
        _clock = Clock::now();
    }

    int libSelected = (std::rand() % _enemyList.size());
    this->loadEnemyLib(_enemyList.at(libSelected));
    std::cout << _pos.x << " " << _pos.y << std::endl;
    _enemyLoaded->getInstance()->setPosition(_pos);
    _enemyLoaded->getInstance()->create(componentManager, entityManager);
}

void EnemyEntity::getLibraries()
{
    std::string symbol = "EnemyEntityEntrypoint";
    std::shared_ptr<DLLloader<IEntityRegister>> enemyLoader;
    std::string filename;
    try {
        for (const auto &entry : std::filesystem::directory_iterator(_path)) {
            filename = entry.path().string();
            enemyLoader.reset();
            enemyLoader = std::make_shared<DLLloader<IEntityRegister>>(filename, symbol);
            if (enemyLoader->getInstance() != NULL) {
                _enemyList.push_back(filename);
            }
        }
    } catch (std::exception &error) {
        throw "Directory ./lib not found";
    }
    if (_enemyList.empty())
        throw "You need a least 1 monster library in directory !";
}

void EnemyEntity::loadEnemyLib(std::string &filename)
{
    std::string symbol = "EnemyEntityEntrypoint";

    _enemyLoaded = std::make_shared<DLLloader<IEntityRegister>>(filename, symbol);
    if (_enemyLoaded->getInstance() == NULL)
        throw filename + " is not a Monster Library !";
}