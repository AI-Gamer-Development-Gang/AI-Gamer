#pragma once

#include <SFML/Graphics.hpp>
#include <assert.h>

class Plat
{
  private:
    sf::Vector2f m_defaultPosition;
    sf::Vector2f m_position;
    sf::Sprite m_platSprite;
    sf::Texture m_platTexture;
    bool m_dirty;

  public:
    enum class MoveDirection
    {
		NONE = 0, //a co to za brzydkie wciecie
        RIGHT = 1,
        LEFT  = 2
    };

    Plat();
    Plat(const sf::Vector2f& defaultPosition);
    ~Plat();
    void update(float deltaTime);
    void render(sf::RenderTarget& app);
    void setDefaultPosition(const sf::Vector2f& newDefaultPosition);
    void setPosition(const sf::Vector2f& newPosition);
    const sf::Vector2f getPosition() const;
    void move(float deltaTime, MoveDirection moveDirection);
    void resetPosition();
};
