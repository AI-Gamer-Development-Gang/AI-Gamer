#include "../Headers/PLAT.h"
#include "../../Configuration/Headers/Defines.h"

Plat::Plat()
    : m_dirty(true)
    , m_defaultPosition(sf::Vector2f(static_cast<float>(rand() % windowSizeX), static_cast<float>(rand() % windowSizeY)))
    , m_position(m_defaultPosition)
{
    assert(m_platTexture.loadFromFile("Images/platform.png"));
    m_platSprite.setTexture(m_platTexture);
}

Plat::Plat(const sf::Vector2f& defaultPosition)
    : m_dirty(true)
    , m_defaultPosition(defaultPosition)
    , m_position(defaultPosition)
{
    assert(m_platTexture.loadFromFile("Images/platform.png"));
    m_platSprite.setTexture(m_platTexture);
}

Plat::~Plat() {}

void Plat::update(float deltaTime) {}

void Plat::setDefaultPosition(const sf::Vector2f& newDefaultPosition) { m_defaultPosition = newDefaultPosition; }
//trzymajmy sie konwencji - jesli wszystkie definicje sa rozwalone na pare linijek to nawet te krotkie niech tez beda

void Plat::setPosition(const sf::Vector2f& newPosition)
{
    m_position = newPosition;
    m_dirty    = true;
}

const sf::Vector2f Plat::getPosition() const { return m_position; }

void Plat::move(float deltaTime, MoveDirection moveDirection) { assert("Function can in future come to development"); }

void Plat::render(sf::RenderTarget& app)
{
    m_dirty = true;
    if (m_dirty)
    {
        m_platSprite.setPosition(m_position);
        app.draw(m_platSprite);
        m_dirty = false;
    }
}

void Plat::resetPosition()
{
    m_position = m_defaultPosition;
    m_dirty    = true;
}
