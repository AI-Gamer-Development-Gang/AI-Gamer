#pragma once
#include <SFML/Graphics.hpp>

class State
{
  public:
    enum class States
    {
        Menu    = 0,
        Game    = 1,
        Results = 2
    };

    virtual void init()                       = 0;
    virtual void setState(States newState) = 0;

    virtual void processInput(const sf::Event& e) = 0;
    virtual void update(const float& delta)       = 0;
    virtual void render(sf::RenderWindow& app)    = 0;
  //tutaj calosc sie rozjechala
};
