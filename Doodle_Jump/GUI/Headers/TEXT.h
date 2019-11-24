#pragma once

#include <SFML/Graphics.hpp>

class TEXT
{
private:
	float _x, _y;
	std::string name;

	sf::Text Name;
public:
	TEXT(float x, float y, std::string name, sf::RenderTarget& app);
	~TEXT();
	void update(float deltaTime);
	sf::Text getTEXT();
};

