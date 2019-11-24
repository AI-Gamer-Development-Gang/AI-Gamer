#include "..\Headers\PlatManager.h"

PlatManager::PlatManager()
{
    for (int i{}; i < 20; ++i)
        m_plats.emplace_back(std::make_unique<Plat>());
}

void PlatManager::update(float deltaTime)
{
    float lastMovingLevel = m_movingLevel;

    if (m_movingUpLimit <= m_movingLevel)
    {
        m_moveDirection = MoveDirection::DOWN;
        m_movingLevel   = m_movingUpLimit - deltaTime * 1000.0f;
    }
    else if (0.0f >= m_movingLevel)
    {
        m_moveDirection = MoveDirection::UP;
        m_movingLevel   = deltaTime * 1000.0f;
    }

    if (m_moveDirection == MoveDirection::UP)
        m_movingLevel += (m_movingUpLimit - m_movingLevel) * deltaTime;
    else
        m_movingLevel -= m_movingLevel * deltaTime;

    incrementGeneralYPosition(m_movingLevel - lastMovingLevel);
}

void PlatManager::render(sf::RenderTarget& app)
{
    for (auto& plat : m_plats)
        plat->render(app);
}

void PlatManager::incrementGeneralYPosition(float deltaY)
{
    for (auto& plat : m_plats)
        plat->setPosition(sf::Vector2f(plat->getPosition() + sf::Vector2f(0.0f, deltaY)));
}
