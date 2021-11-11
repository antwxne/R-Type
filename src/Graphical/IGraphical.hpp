/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** IGraphical
*/

#ifndef IGRAPHICAL_HPP_
#define IGRAPHICAL_HPP_

class IGraphical {
    public:
        virtual ~IGraphical() = default;
        virtual void clear() = 0;
        virtual void display() = 0;
    protected:
    private:
};

#endif /* !IGRAPHICAL_HPP_ */
