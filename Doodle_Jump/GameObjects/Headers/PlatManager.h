#pragma once

#include "Plat.h"
#include <SFML/Graphics.hpp>
#include <assert.h>
#include <vector>

class PlatManager
{
  public:
    PlatManager();
    ~PlatManager() = default;

    void update(float deltaTime);
    void render(sf::RenderTarget& app);
    void incrementGeneralYPosition(float deltaY);

  private:
    std::vector<std::unique_ptr<Plat>> m_plats{};
    const float m_doodleJumpVelocity{350.0f};
    const float m_gravitationalAcceleration{350.f};
    float m_generalYPosition{};
    float m_duration{};
    float m_distance{};
};
