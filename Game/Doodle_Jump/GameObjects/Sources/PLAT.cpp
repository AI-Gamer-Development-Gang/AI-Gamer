#include "../Headers/PLAT.h"

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

void Plat::setPosition( const sf::Vector2f& newPosition)
{
	m_position =newPosition;
    m_dirty = true;
}

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



