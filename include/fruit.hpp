#ifndef fruit_hpp
#define fruit_hpp
#include "../include/game.hpp"
#include "../include/definitions.hpp"

namespace Ikah
{
    class Fruit
    {
        public:
            Fruit(GameDataRef data);
            void update(float dt);
            void render(float dt);
            void binCollision(sf::Sprite bin);
            int getScore();
        private:
            GameDataRef _data;
            sf::Sprite _banana;
            sf::Sprite _bananas[10];

            int sizeOfBananasArr;
            int _score;
            void init();
            void setBananas();
            void moveBananas();
            int randomXPosition(sf::Sprite fruit);
            float randomFloat(float min, float max);
    };
}
#endif