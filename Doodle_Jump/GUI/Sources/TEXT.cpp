#include "../../GUI/Headers/TEXT.h"

TEXT::TEXT(float x, float y, std::string name)
{
	m_Text_Position = {x, y};
	assert(m_Font.loadFromFile("images/arial.ttf"));
	m_Text.setFont(m_Font);
	m_Text.setFillColor(sf::Color::Black);
	m_Text.setStyle(sf::Text::Bold);
	m_Text.setCharacterSize(32);
	m_Text.setString(name);
	sf::FloatRect m_Bounds = m_Text.getLocalBounds();
	m_Text.setOrigin(m_Bounds.left + m_Bounds.width / 2.0f, m_Bounds.top + m_Bounds.height / 2.0f);
	m_Text.setPosition(m_Text_Position);
}

TEXT::~TEXT() {}

void TEXT::update(float deltaTime)
{
}

void TEXT::render(sf::RenderTarget& app)
{
	m_dirty = true;
	if (m_dirty)
	{
		app.draw(m_Text);
		m_dirty = false;
	}
}
