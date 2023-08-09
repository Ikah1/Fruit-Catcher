#include "../include/obstacles.hpp"

namespace Ikah
{
    Obstacles::Obstacles(GameDataRef data):_data(data)
    {
        srand(time(0));

        this->_score = 0;

        this->_data->assets.loadTexture("Bacteria", BACTERIA_FILEPATH);
        this->_bacteria.setTexture(this->_data->assets.getTexture("Bacteria"));

        this->_bacteria.setScale(0.1f, 0.1f);
        this->_bacteria.setOrigin(0, 0);
        setBacteria();
    }

    void Obstacles::update(float dt)
    {
        moveBacteria();
    }

    void Obstacles::render(float dt)
    {
        this->_data->window.draw(this->_bacteria);
    }

    void Obstacles::moveBacteria()
    {
        this->_bacteriaMovement = sf::Vector2f(0, 20);
        this->_bacteria.move(this->_bacteriaMovement);
        if(this->_bacteria.getPosition().y + this->_bacteria.getGlobalBounds().height >= SCREEN_HEIGHT)
        {
            setBacteria();
        }
    }

    void Obstacles::setBacteria()
    {
        int randX = rand() % SCREEN_WIDTH - this->_bacteria.getGlobalBounds().width + this->_bacteria.getGlobalBounds().width;
        this->_bacteria.setPosition(randX, 0);
    }

    void Obstacles::bacteriaCollision(sf::Sprite bin)
    {
        if(this->_bacteria.getGlobalBounds().intersects(bin.getGlobalBounds()))
        {
            setBacteria();
            this->_score -= 50;
        }
    }

    int Obstacles::getScore()
    {
        return this->_score;
    }
}