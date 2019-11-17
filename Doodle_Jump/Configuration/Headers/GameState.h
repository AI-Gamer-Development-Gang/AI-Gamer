#pragma once

#include "../../GameObjects/Headers/Doodle.h"
#include "../../GameObjects/Headers/PLAT.h"
#include "StateManager.h"
#include "State.h"
#include <SFML/Graphics.hpp>
#include <assert.h>

class GameState : public State
{
  public:
    GameState(StateManager* stateManager);
    ~GameState() = default;

    void processInput(const sf::Event& e);
    void update(const float& delta);
    void render(sf::RenderWindow& app);

    void init() override;
    void setState(States newState) override;

  private:
    bool m_isPlaying;
    Plat m_plat;
    Doodle m_doodle;
    StateManager* m_stateManager;
    sf::Texture m_backgroundTexture;
    sf::Sprite m_backgroundSprite;
};
