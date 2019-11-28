#include "..\Headers\PlatManager.h"
#include <math.h>

PlatManager::PlatManager()
{
    for (int i{}; i < 20; ++i)
        m_plats.emplace_back(std::make_unique<Plat>());
}

void PlatManager::update(float deltaTime)
{
    if (m_distance <= 0)
    {
        m_distance = 0;
        m_duration = 0;
    }
    m_duration += deltaTime;
    m_distance = m_doodleJumpVelocity * m_duration - m_gravitationalAcceleration * m_duration * m_duration / 2.0f;
    incrementGeneralYPosition(m_distance);
}

void PlatManager::render(sf::RenderTarget& app)
{
    for (auto& plat : m_plats)
        plat->render(app);
}

void PlatManager::incrementGeneralYPosition(float deltaY)
{
    for (auto& plat : m_plats)
        plat->setPosition(sf::Vector2f(plat->getDefaultPosition() + sf::Vector2f(0.0f, deltaY)));
}
