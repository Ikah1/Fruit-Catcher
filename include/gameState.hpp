#ifndef gameState_hpp
#define gameState_hpp

#include "../include/state.hpp"
#include "../include/game.hpp"
#include "../include/fruit.hpp"
#include "../include/obstacles.hpp"
#include "../include/definitions.hpp"
#include "../include/scoreManager.hpp"

namespace Ikah
{
    class GameState : public State
    {
        public:
            GameState(GameDataRef data);
            void init();
            void handleInput();
            void update(float dt);
            void render(float dt);
        private:
            #define PLAYER_GAP_FROM_BOTTOM 50
            #define SCORE_GAP_TOP 100
            #define SCORE_SIZE 150
            GameDataRef _data;
            sf::Sprite _background;
            sf::Sprite _rustyBin;

            Fruit _fruit;
            Obstacles _obstacles;
            ScoreManager _scoreManager;

            sf::Font _scoreFont;
            sf::Text _scoreText;


            void moveBin();
    };
}

#endif