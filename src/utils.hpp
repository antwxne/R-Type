/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** utils
*/

#include<vector>
#include<algorithm>

template <typename T>

bool contains(std::vector<T> vec, const T & elem)
{
    if(std::find(vec.begin(), vec.end(), elem) != vec.end() )
    {
        return true;
    }
    return false;
}