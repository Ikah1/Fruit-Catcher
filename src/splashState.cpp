#include "../include/splashState.hpp"
#include "../include/mainMenuState.hpp"
#include <sstream>
#include <iostream>

namespace Ikah
{
    SplashState::SplashState(GameDataRef data) : _data(data)
    {

    }

    void SplashState::init()
    {
        this->_data->assets.loadTexture("Splash Background", SPLASH_SCREEN_BACKGROUND_FILEPATH);
        _background.setTexture(this->_data->assets.getTexture("Splash Background"));
    }

    void SplashState::handleInput()
    {
        sf::Event event;
        while(this->_data->window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }
        }
    }

    void SplashState::update(float dt)
    {
        if(this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
        {
            this->_data->manager.addState(StateRef(new MainMenuState(_data)), true);
        }
    }

    void SplashState::render(float dt)
    {
        this->_data->window.clear(sf::Color::Black);
        this->_data->window.draw(this->_background);
        this->_data->window.display();
    }
}