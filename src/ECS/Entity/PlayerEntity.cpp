/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** PlayerEntity
*/

#include "PlayerEntity.hpp"
#include "ECS/component.hpp"

PlayerEntity::PlayerEntity(const Position &pos,  ColorType color): IEntityRegister()
{
    _pos = pos;
    _color = color;
}

PlayerEntity::PlayerEntity(): IEntityRegister()
{
}

PlayerEntity::~PlayerEntity()
{
}

void PlayerEntity::setPos(const Position &pos)
{
    _pos = pos;
}

void PlayerEntity::setColor(ColorType color)
{
    _color = color;
}

void PlayerEntity::create(
    const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManager)
{
    _entity = entityManager->create();

    _textureRect = {0,0, 132, 64};

    componentManager->subToComponent(_entity, Rotate{0});
    componentManager->subToComponent(_entity, _pos);
    componentManager->subToComponent(_entity, Tag{{TagType::PLAYER}});
    componentManager->subToComponent(_entity, Collision{true});
    componentManager->subToComponent(_entity, Texture{TextureType::Player});
    componentManager->subToComponent(_entity, Scale{1, 1});
    componentManager->subToComponent(_entity, Color{_color});
    componentManager->subToComponent(_entity, MoveClock{7});

    std::shared_ptr<sf::Sprite> sprite = std::make_shared<sf::Sprite>();
    sf::Clock clock;

    sprite->setTextureRect(_textureRect);
    componentManager->subToComponent(_entity, Firerate{0.25, clock});
    componentManager->subToComponent(_entity, SfmlSprite{sprite, _textureRect, 4, 0, 1});
    componentManager->subToComponent(_entity, Life{1});
    componentManager->subToComponent(_entity, Speed{20});
    componentManager->subToComponent(_entity, Acceleration{0, 0});
    componentManager->subToComponent(_entity, Rectangle{_textureRect.width, _textureRect.height});
}
