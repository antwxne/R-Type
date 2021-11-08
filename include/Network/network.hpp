/*
** EPITECH PROJECT, 2021
** B-CPP-500-PAR-5-1-babel-alan.sigal
** File description:
** network
*/

#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#define GAME_NAME_MAX_LENGHT 12
#define PLAYER_NAME_MAX_LENGHT 10

enum class MessageType : short
{
    SetPlayerName,
    CreateGame,
    JoinGame,
    LeaveGame,
    GetGamesList,
    GetPlayersInGame,
};

#endif /* !NETWORK_HPP_ */
