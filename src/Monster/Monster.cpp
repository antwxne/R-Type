/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Monster
*/

#include "Monster.hpp"

Monster::Monster(const std::string &path)
{
    _monsterLoaded = NULL;
    _path = path;
}

Monster::~Monster()
{
    std::cout << "THE EEEEEEEEEEEEEEND" << std::endl;
}

void Monster::getLibraries()
{
    std::string symbol = "EnemyEntityEntrypoint";
    std::shared_ptr<DLLloader<IEntityRegister>> monsterLoader;
    std::string filename;
    try {
        for (const auto &entry : std::filesystem::directory_iterator(_path)) {
            filename = entry.path().string();
            monsterLoader.reset();
            monsterLoader = std::make_shared<DLLloader<IEntityRegister>>(filename, symbol);
            if (monsterLoader->getInstance() != NULL) {
                _monsterList.push_back(filename);
            }
        }
    } catch (std::exception &error) {
        throw "Directory ./lib not found";
    }
    if (_monsterList.empty())
        throw "You need a least 1 monster library in directory !";
}

void Monster::loadMonsterLib(std::string &filename)
{
    std::string symbol = "EnemyEntityEntrypoint";

    _monsterLoaded = std::make_shared<DLLloader<IEntityRegister>>(filename, symbol);
    if (_monsterLoaded->getInstance() == NULL)
        throw filename + " is not a Monster Library !";
}

void Monster::create(std::shared_ptr<ComponentManager> componentManager, std::shared_ptr<EntityManager> entityManager, const Position &pos)
{
    std::srand(std::time(nullptr));
    int libSelected = (std::rand() % _monsterList.size());
    this->loadMonsterLib(_monsterList.at(libSelected));
    _monsterLoaded->getInstance()->setPosition(pos);
    _monsterLoaded->getInstance()->create(componentManager, entityManager);
}