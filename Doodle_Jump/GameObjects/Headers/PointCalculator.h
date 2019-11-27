#pragma once

#include <SFML/Graphics.hpp>
#include <assert.h>
#include <sstream>

class PointCalculator
{
private:
	sf::Vector2f  m_PointPosition;
	sf::Text m_Text;
	sf::Font m_Font;
	bool m_dirty;

	std::string str;

	int points = 4; //Dla testów
public:
	PointCalculator();
	~PointCalculator();

	void update(float deltaTime);
	void render(sf::RenderTarget& app);
};

