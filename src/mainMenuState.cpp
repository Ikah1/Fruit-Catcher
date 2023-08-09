#include "../include/mainMenuState.hpp"
#include "../include/definitions.hpp"
#include "../include/GameState.hpp"
#include "../include/mainMenuState.hpp"
#include <iostream>

namespace Ikah
{
    MainMenuState::MainMenuState(GameDataRef data) : _data(data)
    {

    }

    void MainMenuState::init()
    {
        this->_showHelp = false;
        //load textures
        this->_data->assets.loadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
        this->_data->assets.loadTexture("Play Button", MAIN_MENU_PLAY_BUTTON_FILEPATH);
        this->_data->assets.loadTexture("Settings Button", MAIN_MENU_SETTINGS_BUTTON_FILEPATH);
        this->_data->assets.loadTexture("Quit Button", MAIN_MENU_QUIT_BUTTON_FILEPATH);
        this->_data->assets.loadTexture("Shop Button", SHOP_BUTTON_FILEPATH);
        this->_data->assets.loadTexture("Help Button", HELP_BUTTON_FILEPATH);
        this->_data->assets.loadTexture("Help Guide", HELP_GUIDE_FILEPATH);

        //setting textures
        this->_background.setTexture(this->_data->assets.getTexture("Background"));
        this->_playButton.setTexture(this->_data->assets.getTexture("Play Button"));
        this->_settingsButton.setTexture(this->_data->assets.getTexture("Settings Button"));
        this->_quitButton.setTexture(this->_data->assets.getTexture("Quit Button"));
        this->_shopButton.setTexture(this->_data->assets.getTexture("Shop Button"));
        this->_helpButton.setTexture(this->_data->assets.getTexture("Help Button"));
        this->_helpGuide.setTexture(this->_data->assets.getTexture("Help Guide"));

        //setting positions
        this->_playButton.setPosition(SCREEN_WIDTH / 2 - (this->_playButton.getGlobalBounds().width / 2), SCREEN_HEIGHT - (this->_playButton.getGlobalBounds().height) * 8 + GAP_BETWEEN_BUTTONS);

        this->_shopButton.setPosition(SCREEN_WIDTH / 2 - this->_shopButton.getGlobalBounds().width / 2, SCREEN_HEIGHT - this->_shopButton.getGlobalBounds().height * 7 + GAP_BETWEEN_BUTTONS * 2);

        this->_helpButton.setPosition(SCREEN_WIDTH / 2 - this->_helpButton.getGlobalBounds().width / 2, SCREEN_HEIGHT - this->_helpButton.getGlobalBounds().height * 6 + GAP_BETWEEN_BUTTONS * 3);

        this->_settingsButton.setPosition(SCREEN_WIDTH / 2 - (this->_settingsButton.getGlobalBounds().width / 2), SCREEN_HEIGHT - (this->_settingsButton.getGlobalBounds().height) * 5 + GAP_BETWEEN_BUTTONS * 4);

        this->_quitButton.setPosition(SCREEN_WIDTH / 2 - (this->_quitButton.getGlobalBounds().width / 2), SCREEN_HEIGHT - (this->_quitButton.getGlobalBounds().height) * 4 + GAP_BETWEEN_BUTTONS * 5);

        this->_helpGuide.setPosition(0, 0);
    }

    void MainMenuState::handleInput()
    {
        sf::Event event;
        while(this->_data->window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }
            if(this->_data->input.isSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
            {
                this->_data->manager.addState(StateRef(new GameState(_data)), true);
            }
            if(this->_data->input.isSpriteClicked(this->_helpButton, sf::Mouse::Left, this->_data->window))
            {
                this->_showHelp = true;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                this->_showHelp = false;
            }
            if(this->_data->input.isSpriteClicked(this->_quitButton, sf::Mouse::Left, this->_data->window))
            {
                this->_data->window.close();
            }
        }
    }

    void MainMenuState::update(float dt)
    {

    }

    void MainMenuState::render(float dt)
    {
        this->_data->window.clear();
        this->_data->window.draw(this->_background);
        this->_data->window.draw(this->_playButton);
        this->_data->window.draw(this->_helpButton);
        this->_data->window.draw(this->_settingsButton);
        this->_data->window.draw(this->_quitButton);
        this->_data->window.draw(this->_shopButton);
        if (this->_showHelp)
        {
            this->_data->window.draw(this->_helpGuide);
        }
        this->_data->window.display();
    }
}