#pragma once

#include <SFML/Graphics.hpp>
#include <assert.h>

class TEXT
{
private:
	sf::Vector2f m_Text_Position;
	sf::Text m_Text;
	sf::Font m_Font;
	sf::FloatRect m_Bounds = m_Text.getLocalBounds();
	bool m_dirty;
public:
	TEXT(float x, float y, std::string name);
	~TEXT();
	void update(float deltaTime);
	void render(sf::RenderTarget& app);
};

