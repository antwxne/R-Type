/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** EnemyEntity
*/

#include "EnemyEntity.hpp"

EnemyEntity::EnemyEntity(const Position &pos): IEntityRegister()
{
    _pos = pos;
}

EnemyEntity::~EnemyEntity()
{
}

void EnemyEntity::create(ECS &ecs)
{
    _entity = ecs.createEntity();
    std::shared_ptr<sf::Sprite> sprite = std::make_shared<sf::Sprite>();


    ecs.subToComponent(_entity, Rotate{0});
    ecs.subToComponent(_entity, _pos);
    ecs.subToComponent(_entity, Tag{{TagType::ENNEMY}});
    ecs.subToComponent(_entity, Collision{true});
    ecs.subToComponent(_entity, Color{ColorType::None});
    ecs.subToComponent(_entity, AI{false, 0, 0, 800, 1920, 1, 1080});
    ecs.subToComponent(_entity, Rectangle{65, 132});
    ecs.subToComponent(_entity, Speed{1});
    ecs.subToComponent(_entity, Acceleration{0, 0});


    int randNum = rand()%(3-1 + 1) + 1;

    switch (randNum)
    {
        case 1:
            ecs.subToComponent(_entity, Texture{TextureType::Enemy});
            _textureRect = {0, 0, 65, 184};
            ecs.subToComponent(_entity, Scale{2, 2});
            ecs.subToComponent(_entity, SfmlSprite{sprite, _textureRect, 8,0, 0.25});
            break;
        case 2:
            ecs.subToComponent(_entity, Texture{TextureType::Enemy2});
            _textureRect = {0, 0, 125, 121};
            ecs.subToComponent(_entity, Scale{1.5, 1.5});
            ecs.subToComponent(_entity, SfmlSprite{sprite, _textureRect, 3,0, 0.25});
            break;
        default:
            ecs.subToComponent(_entity, Texture{TextureType::Enemy3});
            _textureRect = {0, 0, 65, 66};
            ecs.subToComponent(_entity, Scale{2, 2});
            ecs.subToComponent(_entity, SfmlSprite{sprite, _textureRect, 5,0, 0.25});
            break;
    }

    sprite->setTextureRect(_textureRect);
}
