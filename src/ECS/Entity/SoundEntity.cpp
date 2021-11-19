/*
** EPITECH PROJECT, 2024
** RType
** File description:
** Created by antoine,
*/

#include "SoundEntity.hpp"

SoundEntity::SoundEntity(const std::string &soundPath): _soundPath(soundPath)
{

}

void SoundEntity::create(
    const std::shared_ptr<ComponentManager> &componentManager,
    const std::shared_ptr<EntityManager> &entityManager
)
{
    _entity = entityManager->create();
    std::cout << "new SOUND entity: "<< _entity << std::endl;
    std::shared_ptr<sf::SoundBuffer> tmp = std::make_shared<sf::SoundBuffer>();
    tmp->loadFromFile(_soundPath);

    componentManager->subToComponent(_entity, SfmlSound{true, sf::Sound(*tmp), tmp});
//    componentManager->subToComponent(_entity, Tag{{TagType::SOUND}});
}
