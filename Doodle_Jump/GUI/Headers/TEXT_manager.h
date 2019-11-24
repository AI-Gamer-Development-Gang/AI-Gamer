#pragma once

#include <SFML/Graphics.hpp>
#include "TEXT.h"
#include <iostream>
#include <vector>

class TEXT_manager
{
private:
	std::vector < TEXT > _text;

public:
	TEXT_manager();
	TEXT_manager(sf::RenderTarget& app);
	void update(float deltaTime);
	void render(sf::RenderTarget& app);
};

