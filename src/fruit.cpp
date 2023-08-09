#include "../include/fruit.hpp"
#include <iostream>

namespace Ikah
{

    Fruit::Fruit(GameDataRef data):_data(data)
    {
        init();
    }

    void Fruit::init()
    {
        //setting banana texture
        this->_data->assets.loadTexture("Banana", BANANA_FILEPATH);
        this->_banana.setTexture(this->_data->assets.getTexture("Banana"));

        sizeOfBananasArr = sizeof(this->_bananas) / sizeof(this->_bananas[0]);
        setBananas();

        this->_score = 0;

        srand(time(0));
    }

    void Fruit::update(float dt)
    {
        moveBananas();
    }

    void Fruit::render(float dt)
    {
        for(int i = 0; i < sizeOfBananasArr; i++)
        {
            this->_data->window.draw(this->_bananas[i]);    
        }
    }

    void Fruit::setBananas()
    {
        for(int i = 0; i < sizeOfBananasArr; i++)
        {
            float minScale = 1.0f;
            float maxScale = 1.5f;

            //Random Rotation and X location
            int randRotation = rand() % 360 + 1;
            int randX = rand() % SCREEN_WIDTH - this->_banana.getGlobalBounds().width;

            //Random Scale
            float randWidth = randomFloat(minScale, maxScale);
            float randHeight = randomFloat(minScale, maxScale);

            this->_banana.setScale(randWidth, randHeight);
            this->_banana.setRotation(randRotation);
            this->_banana.setOrigin(this->_banana.getGlobalBounds().width / 2, this->_banana.getGlobalBounds().height / 2);
            this->_banana.setPosition(randX, 0);

            this->_bananas[i] = this->_banana;
        }
    }

    void Fruit::moveBananas()
    {
        for(int i = 0; i < sizeOfBananasArr; i++)
        {
            float minSpeed = 10.0f;
            float maxSpeed = 30.0f;
            float randSpeed = randomFloat(minSpeed, maxSpeed);
            sf::Vector2f bananaMovement(0, randSpeed);
            this->_bananas[i].move(bananaMovement);

            //if banana reaches bottom of screen reset position
            if(this->_bananas[i].getPosition().y + this->_bananas[i].getGlobalBounds().height >= SCREEN_HEIGHT)
            {
                this->_bananas[i].setPosition(randomXPosition(this->_bananas[i]), 0);
            }
        }
    }

    void Fruit::binCollision(sf::Sprite bin)
    {
        for (int i = 0; i < sizeOfBananasArr; i++)
        {
            if(this->_bananas[i].getGlobalBounds().intersects(bin.getGlobalBounds()))
            {
                this->_bananas[i].setPosition(randomXPosition(this->_bananas[i]), 0);
                this->_score += 1;
            }
        }
    }

    int Fruit::getScore()
    {
        return this->_score;
    }

    int Fruit::randomXPosition(sf::Sprite fruit)
    {
        int randWidth = rand() % SCREEN_WIDTH - fruit.getGlobalBounds().width + fruit.getGlobalBounds().width;
        return randWidth;
    }

    float Fruit::randomFloat(float min, float max)
    {
        float random = min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
        return random;
    }
}