#pragma once

#include "Plat.h"
#include <SFML/Graphics.hpp>
#include <assert.h>
#include <vector>

class PlatManager
{
  public:
    enum class MoveDirection
    {
        UP = 0,
        DOWN = 1
    };
    PlatManager();
    ~PlatManager() = default;

    void update(float deltaTime);
    void render(sf::RenderTarget& app);
    void incrementGeneralYPosition(float deltaY);

	
  private:
    std::vector<std::unique_ptr<Plat>> m_plats{};
    const float m_movingStep{5.f};
    const float m_movingDistance{5.f};
    float m_movingLevel{};
    MoveDirection m_moveDirection{MoveDirection::UP};
};
