#pragma once

#include <SFML/Graphics.hpp>
#include "TEXT.h"
#include <iostream>
#include <vector>

class TEXT_manager
{
private:
	std::vector<std::unique_ptr<TEXT>> m_texts{};;

public:
	TEXT_manager();
	~TEXT_manager();
	void update(float deltaTime);
	void render(sf::RenderTarget& app);
};

