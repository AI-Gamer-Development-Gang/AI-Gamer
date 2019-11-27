#pragma once

#include <SFML/Graphics.hpp>
#include "TEXT.h"
#include <vector>

class TEXT_manager
{
private:
	std::vector<std::unique_ptr<TEXT>> m_texts{};

	int m_state;
public:
	TEXT_manager(int m_state);
	~TEXT_manager();

	void update(float deltaTime);
	void render(sf::RenderTarget& app);
};

