/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** FirstMonsterEntity
*/

#include "FirstMonsterEntity.hpp"

FirstMonsterEntity::FirstMonsterEntity() : IEntityRegister()
{
}

FirstMonsterEntity::~FirstMonsterEntity()
{
}

void FirstMonsterEntity::create(std::shared_ptr<ComponentManager> componentManager, std::shared_ptr<EntityManager> entityManager)
{
    _entity = entityManager->create();
    std::shared_ptr<sf::Sprite> sprite = std::make_shared<sf::Sprite>();


    componentManager->subToComponent(_entity, Rotate{0});
    componentManager->subToComponent(_entity, _pos);
    componentManager->subToComponent(_entity, Tag{{TagType::ENNEMY}});
    componentManager->subToComponent(_entity, Collision{true});
    componentManager->subToComponent(_entity, Color{ColorType::None});
    componentManager->subToComponent(_entity, AI{false, 0, 0, 800, 1920, 1, 1080});
    componentManager->subToComponent(_entity, Rectangle{65, 132});
    componentManager->subToComponent(_entity, Speed{1});
    componentManager->subToComponent(_entity, Acceleration{0, 0});

    componentManager->subToComponent(_entity, Texture{TextureType::Enemy});
    _textureRect = {0, 0, 65, 184};
    componentManager->subToComponent(_entity, Scale{2, 2});
    componentManager->subToComponent(_entity, SfmlSprite{sprite, _textureRect, 8,0, 0.25});

    sprite->setTextureRect(_textureRect);
}

extern "C" std::shared_ptr<IEntityRegister> EnemyEntityEntrypoint()
{
    return std::shared_ptr<IEntityRegister>(new FirstMonsterEntity());
}