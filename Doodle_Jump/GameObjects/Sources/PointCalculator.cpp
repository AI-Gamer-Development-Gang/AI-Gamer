#include "../../GameObjects/Headers/PointCalculator.h"

PointCalculator::PointCalculator()
{
	m_PointPosition = { 370.f, 0.f };

	assert(m_Font.loadFromFile("images/arial.ttf"));
	m_Text.setFont(m_Font);
	m_Text.setFillColor(sf::Color::Black);
	m_Text.setStyle(sf::Text::Bold);
	m_Text.setCharacterSize(32);
	
	std::ostringstream itos_points;
	itos_points << points;   //Tutaj podajemy wartoœæ punktów w int, zmienna points
	str = itos_points.str();

	m_Text.setString(str);
	m_Text.setPosition(m_PointPosition);
}

PointCalculator::~PointCalculator() { }

void PointCalculator::update(float deltaTime) { }

void PointCalculator::render(sf::RenderTarget& app)
{
	m_dirty = true;
	if (m_dirty)
	{
		app.draw(m_Text);
		m_dirty = false;
	}
	
}
