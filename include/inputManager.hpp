#ifndef inputManager_hpp
#define inputManager_hpp

#include <SFML/Graphics.hpp>

namespace Ikah
{
    class InputManager
    {
        public:
            InputManager(){};
            ~InputManager(){};

            bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);

            sf::Vector2i getMousePosition(sf::RenderWindow &window);
    };
}

#endif