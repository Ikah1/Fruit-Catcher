#ifndef splashState_hpp
#define splashState_hpp

#include "../include/state.hpp"
#include "../include/game.hpp"

namespace Ikah
{
    class SplashState : public State 
    {
        public:
            SplashState(GameDataRef data);

            void init();
            void handleInput();
            void update(float dt);
            void render(float dt);
        private:
            GameDataRef _data;
            sf::Clock _clock;
            sf::Sprite _background;
    };
}

#endif