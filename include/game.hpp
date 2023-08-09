#ifndef game_hpp
#define game_hpp

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "../include/stateManager.hpp"
#include "../include/assetManager.hpp"
#include "../include/inputManager.hpp"
#include "../include/definitions.hpp"

namespace Ikah
{
    struct GameData
    {
        StateManager manager;
        sf::RenderWindow window;
        AssetManager assets;
        InputManager input;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game
    {
        public:
            Game(int width, int height, std::string title);
        private:
            const float dt = 1.0f / 60.0f;
            sf::Clock _clock;
            GameDataRef _data = std::make_shared<GameData>();
            void run();
    };
}

#endif