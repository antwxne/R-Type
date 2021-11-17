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
    ecs.subToComponent(_entity, Texture{TextureType::Enemy});
    ecs.subToComponent(_entity, Scale{1, 1});
    ecs.subToComponent(_entity, Color{ColorType::None});
    ecs.subToComponent(_entity, AI{false, 0, 0, 800, 1920, 1, 1080});
    ecs.subToComponent(_entity, Rectangle{257, 184});
    _textureRect = {0, 0, 257, 184};
    sprite->setTextureRect(_textureRect);

    ecs.subToComponent(_entity, SfmlSprite{sprite, _textureRect, 4,0});
    ecs.subToComponent(_entity, Speed{1});
    ecs.subToComponent(_entity, Acceleration{0, 0});
}
