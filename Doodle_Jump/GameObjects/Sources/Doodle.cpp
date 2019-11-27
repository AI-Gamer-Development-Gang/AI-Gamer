#include "../Headers/Doodle.h"
#include <iostream>

Doodle::Doodle(const sf::Vector2f& defaultPosition)
    : m_dirty(true)
    , m_defaultPosition(defaultPosition)
    , m_position(defaultPosition)
    , m_movingDirection{MoveDirection::NONE}
{
    assert(m_doodleTexture.loadFromFile("Images/doodle.png"));
    m_doodleSprite.setTexture(m_doodleTexture);
}

Doodle::~Doodle() {}

void Doodle::update(float deltaTime)
{
    switch (m_movingDirection)
    {
    case MoveDirection::LEFT:
        setPosition(sf::Vector2f(m_position.x - deltaTime * 100, m_position.y));
        break;
    case MoveDirection::RIGHT:
        setPosition(sf::Vector2f(m_position.x + deltaTime* 100, m_position.y));
        break;
    case MoveDirection::NONE:
        break;
    default:
        assert("Sth went wrong");
        break;
    }
}

void Doodle::setDefaultPosition(const sf::Vector2f& newDefaultPosition) { m_defaultPosition = newDefaultPosition; }
//trzymajmy sie konwencji - jesli wszystkie definicje sa rozwalone na pare linijek to nawet te krotkie niech tez beda

void Doodle::setPosition(const sf::Vector2f& newPosition)
{
    m_position = newPosition;
    m_dirty    = true;
}

void Doodle::move(const MoveDirection moveDirection) { m_movingDirection = moveDirection; }
//trzymajmy sie konwencji - jesli wszystkie definicje sa rozwalone na pare linijek to nawet te krotkie niech tez beda

void Doodle::render(sf::RenderTarget& app)
{
    m_dirty = true; // Because of SFML
    if (m_dirty)
    {
        m_doodleSprite.setPosition(m_position);
		app.draw(m_doodleSprite);
        m_dirty = false;
    }
}

void Doodle::resetPosition()
{
    m_position = m_defaultPosition;
    m_dirty    = true;
}

void Doodle::processInput(const sf::Event& e)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        move(MoveDirection::LEFT);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        move(MoveDirection::RIGHT);
    else
        move(MoveDirection::NONE);
}
