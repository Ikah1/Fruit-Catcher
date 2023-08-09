#ifndef obsticles_hpp
#include "game.hpp"
#include "../include/definitions.hpp"

namespace Ikah
{
    class Obstacles
    {
        public:
            Obstacles(GameDataRef data);
            void update(float dt);
            void render(float dt);
            void bacteriaCollision(sf::Sprite bin);
            int getScore();
        private:
            GameDataRef _data;
            sf::Sprite _bacteria;

            sf::Vector2f _bacteriaMovement;

            int _score;

            void setBacteria();
            void moveBacteria();
    };
}

#endif