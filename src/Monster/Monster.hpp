/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** Monster
*/

#ifndef MONSTER_HPP_
#define MONSTER_HPP_

#include "../DLLloader/DLLloader.hpp"
#include "../ECS/Entity/IEntityRegister.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <ctime>
#include <cstdlib>

class Monster {
    public:
        Monster(const std::string &path);
        ~Monster();

        void getLibraries();
        void loadMonsterLib(std::string &filename);
        void create(std::shared_ptr<ComponentManager> componentManager,
                    std::shared_ptr<EntityManager> entityManager, const Position &pos);

    protected:
    private:
        std::shared_ptr<DLLloader<IEntityRegister>> _monsterLoaded;
        std::string _path;
        std::vector<std::string> _monsterList;

};

#endif /* !MONSTER_HPP_ */
