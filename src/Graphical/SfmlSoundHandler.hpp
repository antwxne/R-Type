/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-thomas1.tricaud
** File description:
** SfmlSoundHandler
*/

#ifndef SFMLSOUNDHANDLER_HPP_
#define SFMLSOUNDHANDLER_HPP_

#include <map>
#include <memory>
#include <SFML/Audio.hpp>

enum SoundType
{
    Shot = 0,
    Explosion = 1
};

typedef std::map<SoundType, std::shared_ptr<sf::SoundBuffer>> soundMap;

class SfmlSoundHandler {
    public:
        SfmlSoundHandler();
        ~SfmlSoundHandler();
       std::shared_ptr<sf::SoundBuffer> getSoundBuffer(SoundType type);

    protected:
        void addMap(SoundType type, const std::string &path);
    private:
        soundMap _map; 
};

#endif /* !SFMLSOUNDHANDLER_HPP_ */
