/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** AccordeonMonsterEntity
*/

#include "AccordeonMonsterEntity.hpp"

AccordeonMonsterEntity::AccordeonMonsterEntity(): IEntityRegister()
{
}

AccordeonMonsterEntity::~AccordeonMonsterEntity()
{
}

void AccordeonMonsterEntity::create(const std::shared_ptr<ComponentManager> &componentManager, const std::shared_ptr<EntityManager> &entityManager)
{
    _entity = entityManager->create();
    std::shared_ptr<sf::Sprite> sprite = std::make_shared<sf::Sprite>();
    int randFirerate = rand()%(5-1 + 1) + 1;

    componentManager->subToComponent(_entity, Rotate{0});
    componentManager->subToComponent(_entity, _pos);
    componentManager->subToComponent(_entity, Tag{{TagType::ENEMY}});
    componentManager->subToComponent(_entity, Collision{true});
    componentManager->subToComponent(_entity, Color{ColorType::None});
    componentManager->subToComponent(_entity, AI{false, 0, 0, 800, 1920, 1, 1080});
    componentManager->subToComponent(_entity, Rectangle{65, 132});
    componentManager->subToComponent(_entity, Speed{1});
    componentManager->subToComponent(_entity, Life{100});
    componentManager->subToComponent(_entity, Acceleration{0, 0});
    componentManager->subToComponent(_entity, MoveClock{7});
    componentManager->subToComponent(_entity, Firerate{(float)randFirerate, Clock::now()});

    componentManager->subToComponent(_entity, Texture{TextureType::Enemy2});
    _textureRect = {0, 0, 125, 121};
    componentManager->subToComponent(_entity, Scale{1.5, 1.5});
    componentManager->subToComponent(_entity, SfmlSprite{sprite, _textureRect, 3,0, 0.25});

    sprite->setTextureRect(_textureRect);
}

extern "C" std::shared_ptr<IEntityRegister> EnemyEntityEntrypoint()
{
    return std::shared_ptr<IEntityRegister>(new AccordeonMonsterEntity());
}
