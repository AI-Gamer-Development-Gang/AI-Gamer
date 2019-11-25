#include "../../GUI/Headers/TEXT_manager.h"
#include <iostream>

TEXT_manager::TEXT_manager()
{
	m_texts.emplace_back(std::make_unique<TEXT>());
}

TEXT_manager::~TEXT_manager()
{
}


void TEXT_manager::update(float deltaTime)
{
}

void TEXT_manager::render(sf::RenderTarget& app)
{
	std::cout << m_texts.size();
	for (auto& text : m_texts)
		text->render(app);
}
