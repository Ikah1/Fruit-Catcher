#ifndef mainMenuState_hpp
#define mainMenuState_hpp

#include "../include/state.hpp"
#include "game.hpp"

#define GAP_BETWEEN_BUTTONS 25

namespace Ikah
{
    class MainMenuState : public State
    {
        public:
            MainMenuState(GameDataRef data);
            void init();
            void handleInput();
            void update(float dt);
            void render(float dt);

        private:
            GameDataRef _data;
            sf::Sprite _background;
            sf::Sprite _playButton;
            sf::Sprite _settingsButton;
            sf::Sprite _quitButton;
            sf::Sprite _helpButton;
            sf::Sprite _shopButton;

            sf::Sprite _helpGuide;
            bool _showHelp;
    };
}

#endif