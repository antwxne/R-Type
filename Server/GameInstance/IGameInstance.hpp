/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** IGameInstance
*/

#ifndef IGAMEINSTANCE_HPP_
#define IGAMEINSTANCE_HPP_

class IGameInstance {
    public:
        virtual ~IGameInstance() = default;
        virtual void run() = 0;
        virtual void startGame() = 0;

    protected:
    private:
};

#endif /* !IGAMEINSTANCE_HPP_ */
