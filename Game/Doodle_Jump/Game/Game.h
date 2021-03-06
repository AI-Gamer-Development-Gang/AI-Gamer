#include <SFML/Graphics.hpp>
#include <assert.h>
#include "../GameObjects/Headers/Doodle.h"
#include "../GameObjects/Headers/PLAT.h"

#pragma once
class Game
{
  public:
    Game();
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    ~Game(){};
    static Game& getInstance();

    void processInput(const sf::Event& e);
    void update(const float& delta);
    void render(sf::RenderWindow& app);

    const bool getEndStatus() const;

  private:
    bool m_isPlaying;
    bool m_exitStatus;
    static Game* m_instance;
    bool test;
    Plat m_plat;
    Doodle m_doodle;

    sf::Texture m_backgroundTexture;
    sf::Sprite m_backgroundSprite;
};
