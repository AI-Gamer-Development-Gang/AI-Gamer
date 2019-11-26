#include "..\Headers\PlatManager.h"
#include <math.h>

PlatManager::PlatManager()
{
    for (int i{}; i < 20; ++i)
        m_plats.emplace_back(std::make_unique<Plat>());
}

void PlatManager::update(float deltaTime) {}
//trzymajmy sie konwencji - jesli wszystkie definicje sa rozwalone na pare linijek to nawet te krotkie niech tez beda
//tutaj nie jestem tego pewien w sumie xd
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
