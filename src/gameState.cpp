#include "../include/gameState.hpp"

bool moveLeft = false;
bool moveRight = false;
sf::Vector2f playerMovement;

namespace Ikah
{
    GameState::GameState(GameDataRef data):_data(data), _fruit(data), _obstacles(data)
    {
        
    }

    void GameState::init()
    {
        //load textures
        this->_data->assets.loadTexture("Background 01", BACKGROUND_01_FILEPATH);
        this->_data->assets.loadTexture("Rusty Bin", RUSTY_BIN_FILEPATH);
        //set textures
        this->_background.setTexture(this->_data->assets.getTexture("Background 01"));
        this->_rustyBin.setTexture(this->_data->assets.getTexture("Rusty Bin"));

        //Setting Positions
        this->_rustyBin.setPosition(SCREEN_WIDTH / 2 - (this->_rustyBin.getGlobalBounds().width / 2), SCREEN_HEIGHT - this->_rustyBin.getGlobalBounds().height - PLAYER_GAP_FROM_BOTTOM);

        //score init
        this->_scoreManager.loadScore();
        this->_scoreFont.loadFromFile(SCORE_FONT_FILEPATH);
        this->_scoreText.setString(std::to_string(this->_scoreManager.getScore()));
        this->_scoreText.setCharacterSize(SCORE_SIZE);
        this->_scoreText.setFont(_scoreFont);
        this->_scoreText.setPosition(SCREEN_WIDTH / 2 - this->_scoreText.getGlobalBounds().width, SCORE_GAP_TOP);

        srand(time(0));

        playerMovement = sf::Vector2f(0, 0);
    }

    void GameState::handleInput()
    {
        sf::Event event;
        while(this->_data->window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    this->_scoreManager.saveScore();
                    this->_data->window.close();
                    break;
                case sf::Event::KeyPressed:
                    switch(event.key.code)
                    {
                        case sf::Keyboard::A:
                            moveLeft = true;
                            break;
                        case sf::Keyboard::D:
                            moveRight = true;
                            break;
                        case sf::Keyboard::Escape:
                            this->_scoreManager.saveScore();
                            this->_data->window.close();
                            break;
                    }
                    break;
                case sf::Event::KeyReleased:
                    switch(event.key.code)
                    {
                        case sf::Keyboard::A:
                            moveLeft = false;
                            break;
                        case sf::Keyboard::D:
                            moveRight = false;
                            break;
                    }
                    break;
            }
        }
    }

    void GameState::update(float dt)
    {
        moveBin();
        this->_fruit.update(dt);
        this->_obstacles.update(dt);
        this->_fruit.binCollision(this->_rustyBin);
        this->_obstacles.bacteriaCollision(this->_rustyBin);
        this->_scoreManager.setScore(this->_fruit.getScore() + this->_obstacles.getScore());
        this->_scoreText.setString(std::to_string(this->_scoreManager.getScore()));
    }

    void GameState::render(float dt)
    {
        this->_data->window.clear();
        this->_data->window.draw(this->_background);
        this->_fruit.render(dt);
        this->_obstacles.render(dt);
        this->_data->window.draw(this->_scoreText);
        this->_data->window.draw(this->_rustyBin);
        this->_data->window.display();
    }

    void GameState::moveBin()
    {
        if(moveLeft)
        {
            if(this->_rustyBin.getPosition().x >= 0)
            {
                playerMovement.x = -1;
                this->_rustyBin.move(playerMovement * MOVEMENT_VELOCITY);
            }
        }
        if(moveRight)
        {
            if(this->_rustyBin.getPosition().x <= SCREEN_WIDTH - this->_rustyBin.getGlobalBounds().width)
            {
                playerMovement.x = 1;
                this->_rustyBin.move(playerMovement * MOVEMENT_VELOCITY);
            }
        }
    }
}