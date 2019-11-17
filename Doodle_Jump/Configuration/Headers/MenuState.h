#pragma once

#include "State.h"
#include "StateManager.h"
#include <SFML/Graphics.hpp>

class MenuState : public State
{
  public:
    MenuState(StateManager* stateManager);
    ~MenuState() = default;

    void processInput(const sf::Event& e);
    void update(const float& delta);
    void render(sf::RenderWindow& app);

    void init() override;
    void setState(States newState) override;

  private:
    StateManager* m_stateManager;
    sf::Texture m_backgroundTexture;
    sf::Sprite m_backgroundSprite;
};