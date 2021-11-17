/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** EnemyEntity
*/

#include "EnemyEntity.hpp"

EnemyEntity::EnemyEntity(const Position &pos)
{
    _pos = pos;
}

EnemyEntity::~EnemyEntity()
{
}

void EnemyEntity::create(ECS &ecs)
{
    Entity enemy = ecs.createEntity();
    std::shared_ptr<sf::Sprite> sprite = std::make_shared<sf::Sprite>();


    ecs.subToComponent(enemy, Rotate{0});
    ecs.subToComponent(enemy, _pos);
    ecs.subToComponent(enemy, Tag{{TagType::ENNEMY}});
    ecs.subToComponent(enemy, Texture{TextureType::Enemy});
    ecs.subToComponent(enemy, Scale{1, 1});
    ecs.subToComponent(enemy, Color{ColorType::None});
    ecs.subToComponent(enemy, AI{false, 0, 0, 800, 1920, 1, 1080});
    ecs.subToComponent(enemy, Rectangle{257, 184});
    _textureRect = {0, 0, 257, 184};
    sprite->setTextureRect(_textureRect);

    ecs.subToComponent(enemy, SfmlSprite{sprite, _textureRect, 4,0});
    ecs.subToComponent(enemy, Speed{1});
    ecs.subToComponent(enemy, Acceleration{0, 0});
}
