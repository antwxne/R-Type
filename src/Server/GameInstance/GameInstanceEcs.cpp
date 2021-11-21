/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** GameInstanceEcs
*/

#include "GameInstanceEcs.hpp"
#include "ECS/component.hpp"
#include "ECS/system.hpp"
#include "ECS/Entity/EnemyEntity.hpp"
#include "ECS/Entity/RoundEntity.hpp"
#include "ECS/Entity/PlayerEntity.hpp"
#include "ECS/Entity/BonusEntity.hpp"
#include "GameInstance.hpp"
#include "NetworkEntityInformation.hpp"

typedef std::chrono::high_resolution_clock Clock;

GameInstanceEcs::GameInstanceEcs(GameInstance &gameInstance) : _gameInstance(gameInstance)
{
    registerComponents();
    registerSystems();
    _networkSendClock = Clock::now();
}

GameInstanceEcs::~GameInstanceEcs()
{
}


void GameInstanceEcs::registerComponents()
{
    _ecs.registerComponent<Position>();
    _ecs.registerComponent<Speed>();
    _ecs.registerComponent<Acceleration>();
    _ecs.registerComponent<Texture>();
    _ecs.registerComponent<Acceleration>();
    _ecs.registerComponent<Scale>();
    _ecs.registerComponent<Rotate>();
    _ecs.registerComponent<ExploseClock>();
    _ecs.registerComponent<Color>();
    _ecs.registerComponent<SfmlSprite>();
    _ecs.registerComponent<Collision>();
    _ecs.registerComponent<Hitbox>();
    _ecs.registerComponent<Tag>();
    _ecs.registerComponent<Life>();
    _ecs.registerComponent<Rectangle>();
    _ecs.registerComponent<Firerate>();
    _ecs.registerComponent<AI>();
    _ecs.registerComponent<MoveClock>();
    _ecs.registerComponent<Round>();
    _ecs.registerComponent<Bonus>();
}

void GameInstanceEcs::registerSystems()
{
    _ecs.registerSystem<MoveSystem>();
    _ecs.registerSystem<AISystem>();
    _ecs.registerSystem<ColissionSystem>();
    _ecs.registerSystem<RoundSystem>();
    _ecs.registerSystem<EnemyShootSystem>();
    _ecs.registerSystem<BonusSystem>();

    auto &evtManager = _ecs.registerSystem<EventSystem>();

    RoundEntity round({0, -110, 5});
    round.create(_ecs.getComponentManager(), _ecs.getEntityManager());
}

void GameInstanceEcs::networkEntityUpdate()
{
    auto delay = std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - _networkSendClock).count();
    if (delay < NETWORK_ENTITY_SEND_MS_DELAY)
        return;
    
    for (auto &i : _ecs.getEntityManager()->getCurrentEntities())
    {
        getCurrentEntityInfo(i);
        handleNetworkGameInfos(i);
    }

    _networkSendClock = Clock::now();
}

void GameInstanceEcs::handleNetworkGameInfos(const Entity &entity)
{
    auto &rounds = _ecs.getComponentManager()->getComponentsList<Round>();

    if (rounds[entity].has_value() == false)
        return;
    auto &round = rounds[entity].value();

    _gameInstance.sendGameInfos(round.score, round.round);
}

void GameInstanceEcs::getCurrentEntityInfo(const Entity &entity)
{
    if (!checkNetworkEntity(entity))
        return;

    std::size_t ent;
    entity >> ent;

    Rotate &rotate = _ecs.getComponent<Rotate>(entity).value();
    Color &color = _ecs.getComponent<Color>(entity).value();
    Texture &texture = _ecs.getComponent<Texture>(entity).value();
    Scale &scale = _ecs.getComponent<Scale>(entity).value();
    Speed &speed = _ecs.getComponent<Speed>(entity).value();
    Acceleration & acceleration = _ecs.getComponent<Acceleration>(entity).value();
    Position &position = _ecs.getComponent<Position>(entity).value();
    SfmlSprite &sprite = _ecs.getComponent<SfmlSprite>(entity).value();

    NetworkEntityInformation info = {ent, position, acceleration, speed, color, rotate, texture, scale,
    sprite.totalRect, sprite.animationSpeed,  sprite.textureRect};

    _gameInstance.sendEntityUpdateMessage(info);
}

bool GameInstanceEcs::checkNetworkEntity(const Entity &entity)
{
    std::size_t ent;
    entity >> ent;

    auto &rotate = _ecs.getComponentManager()->getComponentsList<Rotate>();
    auto &color = _ecs.getComponentManager()->getComponentsList<Color>();
    auto &texture = _ecs.getComponentManager()->getComponentsList<Texture>();
    auto &scale = _ecs.getComponentManager()->getComponentsList<Scale>();
    auto &speed = _ecs.getComponentManager()->getComponentsList<Speed>();
    auto &acceleration = _ecs.getComponentManager()->getComponentsList<Acceleration>();
    auto &position = _ecs.getComponentManager()->getComponentsList<Position>();
    auto &sprite = _ecs.getComponentManager()->getComponentsList<SfmlSprite>();

    return rotate[ent].has_value() && color[ent].has_value() &&
        texture[ent].has_value() && scale[ent].has_value() && speed[ent].has_value()
        && acceleration[ent].has_value() && position[ent].has_value() && sprite[ent].has_value();
}

void GameInstanceEcs::handleNewPlayer(int nPlayer)
{
    PlayerEntity entity;
    auto &evtManager = _ecs.registerSystem<EventSystem>();

    switch (nPlayer)
    {
        case 1:
        {
            entity.setPos({100, 100});
            entity.setColor(ColorType::Blue);
            break;
        }
        case 2:
        {
            entity.setPos({100, 300});
            entity.setColor(ColorType::Red);
            break;
        }
        case 3:
        {
            entity.setPos({100, 500});
            entity.setColor(ColorType::Yellow);
            break;
        }
        default:
        {
            entity.setPos({100, 700});
            entity.setColor(ColorType::Green);
        }
    }
    entity.create(_ecs.getComponentManager(), _ecs.getEntityManager());
    evtManager.subscribeToEvent(ControlGame::RIGHT, entity.getEntity(), std::bind(EventCallback::changeAccelerationRIGHT, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    evtManager.subscribeToEvent(ControlGame::UP, entity.getEntity(), std::bind(EventCallback::changeAccelerationUP, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    evtManager.subscribeToEvent(ControlGame::DOWN, entity.getEntity(), std::bind(EventCallback::changeAccelerationDOWN, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    evtManager.subscribeToEvent(ControlGame::LEFT, entity.getEntity(), std::bind(EventCallback::changeAccelerationLEFT, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
    evtManager.subscribeToEvent(ControlGame::SPACE, entity.getEntity(), std::bind(EventCallback::shoot, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,std::placeholders::_4));
    _playerToEntityMap[nPlayer] = entity.getEntityValue();
}

void GameInstanceEcs::handleCommandPlayer(int nPlayer, ControlGame control)
{
    try
    {
        std::size_t entityPlayer = _playerToEntityMap[nPlayer];

        _ecs.getSystem<EventSystem>().setEvents(entityPlayer, control);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error handle command : "<< e.what() << '\n';
    }
}

void GameInstanceEcs::run()
{
    _ecs.getSystem<EventSystem>().update();
    _ecs.getSystem<ColissionSystem>().update();
    _ecs.getSystem<AISystem>().update();
    _ecs.getSystem<MoveSystem>().update();
    _ecs.getSystem<RoundSystem>().update();
    _ecs.getSystem<EnemyShootSystem>().update();
    _ecs.getSystem<BonusSystem>().update();
    _ecs.garbageCollector(_raisedEvents);
    networkEntityUpdate();
    handleRaisedEvents();
}

void GameInstanceEcs::handleRaisedEvents()
{
    auto &event = _ecs.getSystem<EventSystem>();

    std::vector<RaisedEvent> eventRaised = event.getRaisedEvents();

    for (auto &i: eventRaised)
    {
        _raisedEvents.push_back({0, i});
    }

    sendDestructionMessage(_raisedEvents);
    _raisedEvents.clear();
    event.clearRaisedEvents();
}

void GameInstanceEcs::sendDestructionMessage(const std::vector<std::pair<std::size_t, RaisedEvent>> &events)
{
    _gameInstance.sendEntityRaisedEvent(events);
}